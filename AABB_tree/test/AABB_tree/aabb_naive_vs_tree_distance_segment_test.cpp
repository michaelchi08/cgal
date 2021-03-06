// Copyright (c) 2009 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0+
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description :
//
//******************************************************************************

#include <fstream>
#include <iostream>

#include <CGAL/Timer.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/Polyhedron_3.h>

#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>

#include "AABB_test_util.h"


template<class K, class Tree, class Polyhedron, Primitive_type Type>
void test_impl(Tree& tree, Polyhedron& p, const double duration)
{
  tree.accelerate_distance_queries(p.points_begin(),p.points_end());

  typedef Tree_vs_naive<Tree, Polyhedron, K, Type> Tester;
  Tester tester(tree, p);

  tester.test_all_distance_methods(duration);
}

int main(void)
{
  std::cout << "AABB naive vs tree distance (segment primitive) tests" << std::endl;

  const double duration = 0.1;
  test_kernels<SEGMENT>("./data/cube.off",duration);
  test_kernels<SEGMENT>("./data/coverrear.off",duration);
  test_kernels<SEGMENT>("./data/finger.off",duration);
  test_kernels<SEGMENT>("./data/pinion.off",duration);

  return EXIT_SUCCESS;
}
