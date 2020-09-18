//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "Component3dReconstructionCore.hh"
#include <algorithm>

// constructor
Component3dReconstructionCore::Component3dReconstructionCore()
	: kinfu(nullptr),
	  params(nullptr)
{
	std::cout << "constructor Component3dReconstructionCore\n";
	cv::setUseOptimized(true); // use OpenCL
	params = cv::kinfu::Params::defaultParams();
}

void Component3dReconstructionCore::setInitialParameters(const ParameterStateStruct& p)
{
	if (p.getSettings().getVolumeType() == ParameterStateStruct::settingsType::volumeTypeType::TSDF)
	{
		params->volumeType = cv::kinfu::VolumeType::TSDF;
	}
	else if (p.getSettings().getVolumeType() == ParameterStateStruct::settingsType::volumeTypeType::HASHTSDF)
	{
		params->volumeType = cv::kinfu::VolumeType::HASHTSDF;
	}
	else
	{
		std::cerr << "unrecognized volume type " << p.getSettings().getVolumeType() << ", using default\n";
	}

	params->depthFactor = p.getSettings().getDepthFactor();
	params->bilateral_sigma_depth = p.getBilateral().getSigmaDepth();
	params->bilateral_sigma_spatial = p.getBilateral().getSigmaSpatial();
	params->bilateral_kernel_size = p.getBilateral().getKernelSize();
	params->icpAngleThresh = p.getIcp().getAngleThresh();
	params->icpDistThresh = p.getIcp().getDistThresh();
	params->icpIterations = {10, 5, 4};
	params->icpIterations = {p.getIcp().getIteration1(), p.getIcp().getIteration2(), p.getIcp().getIteration3(),
			p.getIcp().getIteration4(), p.getIcp().getIteration5()};
	std::remove(params->icpIterations.begin(), params->icpIterations.end(), 0);
	params->pyramidLevels = p.getIcp().getPyramidLevels();
	params->tsdf_min_camera_movement = p.getTsdf().getMinCameraMovement();
	params->volumeDims = cv::Vec3i(p.getVolumeDims().getX(), p.getVolumeDims().getY(), p.getVolumeDims().getZ());
	params->voxelSize = p.getSettings().getVoxelSize();
	params->volumePose = cv::Affine3f(
			cv::Matx33f(
				p.getVolumePose().getRotXX(), p.getVolumePose().getRotXY(), p.getVolumePose().getRotXZ(),
				p.getVolumePose().getRotYX(), p.getVolumePose().getRotYY(), p.getVolumePose().getRotYZ(),
				p.getVolumePose().getRotZX(), p.getVolumePose().getRotZY(), p.getVolumePose().getRotZZ()
			),
			cv::Vec3f(p.getVolumePose().getTranslX(), p.getVolumePose().getTranslY(), p.getVolumePose().getTranslZ()));
	params->tsdf_trunc_dist = p.getTsdf().getTruncDist();
	params->tsdf_max_weight = p.getTsdf().getMaxWeight();
	params->raycast_step_factor = p.getSettings().getRaycastStepFactor();
	params->lightPose = cv::Vec3f(p.getLightPose().getX(), p.getLightPose().getY(), p.getLightPose().getZ());
	params->truncateThreshold = p.getSettings().getTruncateThreshold();
}

void Component3dReconstructionCore::fromCvMat(const cv::Mat& in, DomainVision::Comm3dPointCloud& out)
{
	out.set_size(in.rows);

	for (int i = 0; i < in.rows; i++)
	{
		auto point = in.at<cv::Vec3f>(i);
		out.set_point(i, point.val[0], point.val[1], point.val[2], 1.0);
	}
}
