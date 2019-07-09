import tensorflow as tf
import os
import sys
from copy import copy
from model.pipeline import Pipeline

from tensorflow.python import debug as tf_debug


if __name__ == "__main__":

    num_keypoints = 30
    patch_feature_dim = 8
    decoding_levels = 5
    kp_transform_loss = 1e4

    recon_weight = 0.001

    learning_rate=0.01

    keypoint_separation_bandwidth=0.04
    keypoint_separation_loss_weight = 10.0

    opt = {
        "optimizer": "Adam",
        "data_name": "aflw_80x80",
        "recon_name": "gaussian_fixedvar_in_01",
        "encoder_name": "general_80x80",
        "decoder_name": "general_80x80",
        "latent_dim": num_keypoints*2+(num_keypoints+1)*patch_feature_dim,
        "train_color_jittering": True,
        "train_random_mirroring": False,
        "train_batch_size": 8,
        "train_shuffle_capacity": 1000,
        "learning_rate": learning_rate,
        "max_epochs": 2000, 
        "weight_decay": 1e-6,
        "test_steps": 5000,   
        "test_limit": 200,
        "recon_weight": recon_weight,
    }

    opt["encoder_options"] = {
        "keypoint_num": num_keypoints,
        "patch_feature_dim": patch_feature_dim,
        "ae_recon_type": opt["recon_name"], 
        "keypoint_concentration_loss_weight": 100.,
        "keypoint_axis_balancing_loss_weight": 200.,
        "keypoint_separation_loss_weight": keypoint_separation_loss_weight,
        "keypoint_separation_bandwidth": keypoint_separation_bandwidth,
        "keypoint_transform_loss_weight": kp_transform_loss,
        "keypoint_decoding_heatmap_levels": decoding_levels,
        "keypoint_decoding_heatmap_level_base": 0.5**(1/2),
        "image_channels": 3,
    }
    opt["decoder_options"] = copy(opt["encoder_options"])

    # -------------------------------------
    model_dir = os.path.join("results/aflw_30")
    checkpoint_dir = 'pretrained_results'
    checkpoint_filename = 'celeba_30/model/snapshot_step_205317'
    vp = Pipeline(None, opt, model_dir=model_dir)
    print(vp.opt)
    with vp.graph.as_default():
        sess = vp.create_session()
        vp.run_full_train_from_checkpoint(sess, checkpoint_dir = checkpoint_dir, checkpoint_filename=checkpoint_filename)
        vp.run_full_test(sess)
