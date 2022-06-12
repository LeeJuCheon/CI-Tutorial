//
// Created by changh95 on 5/26/22.
//

#ifndef SVSLAM_CLASS_HPP
#define SVSLAM_CLASS_HPP

#define USING_EASY_PROFILER
#include "easy/profiler.h"
#include "spdlog/spdlog.h"
#include "Eigen/Dense"
#include <unistd.h>

struct Landmark3DPosition
{
    double x;
    double y;
    double z;
};

struct IntrinsicMatrix
{
    double fx;
    double fy;
    double cx;
    double cy;
};

struct ExtrinsicMatrix
{
    Eigen::Matrix3d rotation_matrix;
    Eigen::Vector3d translation;
};


// class ImageProjector
// {
// public:
//     ImageProjector(const Landmark3DPosition& point3D, const IntrinsicMatrix& intrinsicMatrix, const ExtrinsicMatrix& extrinsicMatrix){
//         std::ignore = point3D;
//         std::ignore = intrinsicMatrix;
//         std::ignore = extrinsicMatrix;
//     };
// private:

// };

struct ProjectedPoints
{
    double u;
    double v;
};

ProjectedPoints project_points(const Landmark3DPosition& point3D, const IntrinsicMatrix& intrinsics, const ExtrinsicMatrix& extrinsics)
{
    std::ignore = point3D;
    std::ignore = intrinsics;
    std::ignore = extrinsics;
    return ProjectedPoints{};
}

#endif  // SVSLAM_CLASS_HPP
