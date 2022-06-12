#include <memory>
#include "gtest/gtest.h"

#include "ImageProjector/ImageProjector.hpp"

/**
 * Design choices:
 * 
 * s[u,v,1]^T = K * [R|t] * [X,Y,Z,1]^T
 * 
 * 1. ImageProjector must be a function
 * 2. The following inputs must be given : 3D point's location (x,y,z), Extrinsic matrix, intrinsic matrix
 *    2.1 x,y,z should be given as double 
 *    2.2 Components of extrinsic matrix (Rotation, Translation) should be given double
 *    2.3 Components of intrinsic matrix (fx, fy, cx, cy) should be given double
 * 3. ImageProjector will output [u,v] as pixel locations.
 *    3.1 u,v should be represented as double.
 */

TEST(Image_Projector, constructor)
{


  constexpr Landmark3DPosition point3D={1.0,0.0,0.0};
  constexpr IntrinsicMatrix intrinsic ={1.0, 1.0, 320.0, 240.0};
  const ExtrinsicMatrix extrinsic = {Eigen::Matrix3d::Identity(), Eigen::Vector3d{0.0,0.0,0.0}};

  // const auto projector = std::make_shared<ImageProjector>(point3D,intrinsic,extrinsic);
  // EXPECT_NE(projector, nullptr);

  constexpr ProjectedPoints uv = {1.0,1.0};

  const auto projected_points = project_points(point3D,intrinsic, extrinsic);
  EXPECT_EQ(projected_points.u, uv.u);
  EXPECT_EQ(projected_points.v, uv.v);
}