#ifndef CPP_BBDETECTOR_H
#define CPP_BBDETECTOR_H

#include <caffe/caffe.hpp>
#include <string>

#include "Detector.h"

class BBDetector : public Detector {
public:
    BBDetector(const std::string &model_file,
               const std::string &weights_file,
               const std::string &mean_file,
               const std::string &mean_value);

    BBDetector();

    std::vector<Detection> detect(const cv::Mat &image) override;

private:
    void SetMean(const std::string& mean_file, const std::string& mean_value);

    void WrapInputLayer(std::vector<cv::Mat>* input_channels);

    void Preprocess(const cv::Mat& img,
                    std::vector<cv::Mat>* input_channels);

    std::shared_ptr<caffe::Net<float> > net_;
    cv::Size input_geometry_;
    int num_channels_;
    cv::Mat mean_;
};


#endif //CPP_BBDETECTOR_H