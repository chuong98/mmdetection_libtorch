//
// Created by dl on 2020/4/12.
//

#ifndef DETECTOR_AnchorPointGenerator_HPP
#define DETECTOR_AnchorPointGenerator_HPP
#include <vector>
#include "torch/torch.h"
#include "torch/script.h"

class AnchorPointGenerator {

public:
    AnchorPointGenerator(int base_size, const std::vector<float>& scales, const std::vector<float>& ratios,
                    bool scale_major = true, const std::vector<float>& ctr = {});
    AnchorPointGenerator();
    ~AnchorPointGenerator();
    void gen_base_anchors();

    torch::Tensor grid_anchors(int stride, torch::DeviceType device);
    torch::Tensor grid_points(int feat_h, int feat_w, int stride, torch::DeviceType device);
public:
    torch::Tensor base_anchors_;
    int anchor_nums_;

    std::vector<int> feature_maps_sizes_;

private:
    int base_size_;
    torch::Tensor scales_;
    torch::Tensor ratios_;
    bool scale_major_;
    std::vector<float> ctr_;


};


#endif //DETECTOR_AnchorPointGenerator_HPP
