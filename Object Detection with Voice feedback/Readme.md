We implemented yolov3 algorithm and used that to detect multiple objects in one image and generate audio file which generates speech based describing the objects in the image.
We used pretrained model weights and drew bounding boxes to the objects detected in the image.The model identified objects with a confidence of about 99%.
We used pretrained weights for the model since to train the model it would have taken a huge amount of time mainly due to the depth of the model and the large size of the dataset.
We converted the text labels produced along with their position to audio files to help people hear what they cannot see. We used the google text to speech api(gTTs) for performing this task.

![image](https://github.com/harithar1234/Projects_Placements/assets/86344120/f8a50399-96bd-409a-aac9-76b63063cc4c)

![image](https://github.com/harithar1234/Projects_Placements/assets/86344120/a9d23ef5-fcec-4b4f-badc-7ab61bcf328a)

