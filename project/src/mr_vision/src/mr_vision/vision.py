#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Image
from ros_numpy import numpify, msgify
import rospkg

import numpy as np
import tensorflow as tf
from object_detection.utils import label_map_util
from object_detection.utils import visualization_utils as viz_utils
import os

path_to_pb = "/home/dixuan/Document/robotique/project/src/mr_vision/model/model"
path_to_labels = "/home/dixuan/Document/robotique/project/src/mr_vision/label_map.pbtxt"

class Vision:
    def __init__(self):
        self.category_index = label_map_util.create_category_index_from_labelmap(path_to_labels, use_display_name=True)
        self.detect_fn = tf.saved_model.load(path_to_pb)

        rospack = rospkg.RosPack()
        path = rospack.get_path('mr_vision') # path is the path to the package mr_vision
        self.image_sub = rospy.Subscriber('/rrbot/camera1/image_raw', Image, self.img_cb)
        self.image_pub = rospy.Publisher('/stop_sign', Image)

        



    def img_cb(self, img):
        rospy.loginfo('received an image')
        image_np = numpify(img)
        
        input_tensor = tf.convert_to_tensor(image_np)
        input_tensor = input_tensor[tf.newaxis, ...]

        detections = self.detect_fn(input_tensor)

        num_detections = int(detections.pop('num_detections'))
        detections = {key: value[0, :num_detections].numpy()
                      for key, value in detections.items()}
        detections['num_detections'] = num_detections

        detections['detection_classes'] = detections['detection_classes'].astype(np.int64)

        image_np_with_detections = image_np.copy()

        viz_utils.visualize_boxes_and_labels_on_image_array(
              image_np_with_detections,
              detections['detection_boxes'],
              detections['detection_classes'],
              detections['detection_scores'],
              self.category_index,
              use_normalized_coordinates=True,
              max_boxes_to_draw=200,
              min_score_thresh=.30,
              agnostic_mode=False)

        self.image_pub.publish(msgify(Image, image_np_with_detections, encoding='rgb8'))

if __name__ == '__main__':
    rospy.init_node('vision', anonymous=True)
    vision = Vision()
    rospy.spin()
