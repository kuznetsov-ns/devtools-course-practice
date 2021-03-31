// Copyright 2021 Kuznetsov Nikita

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Kuznetsov_Nikita_ComplexNumberTest, Can_Copy_Element) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z1(re, im);

    ComplexNumber z2(z1);
    bool sw = z1 == z2;

    ASSERT_TRUE(sw);
}

typedef testing::TestWithParam<std::tuple<double, double>>
Kuznetsov_Nikita_ComplexNumberTest_param;
TEST_P(Kuznetsov_Nikita_ComplexNumberTest_param, Can_Sum_Elements) {
  double re = std::get<0>(GetParam());
  double im = std::get<1>(GetParam());
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);

  ComplexNumber sum = z1 + z2;

  ASSERT_EQ(sum, ComplexNumber(2 * re, 2 * im));
}

TEST_P(Kuznetsov_Nikita_ComplexNumberTest_param, Can_Multiply_Elements) {
  double re = std::get<0>(GetParam());
  double im = std::get<1>(GetParam());
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);

  ComplexNumber result = z1 * z2;

  ASSERT_EQ(result, ComplexNumber(re * re - im * im, re * im + im * re));
}
INSTANTIATE_TEST_CASE_P(/**/, Kuznetsov_Nikita_ComplexNumberTest_param,
  testing::Combine(
    testing::Values(-10.0, 2.0),
    testing::Values(5.0, -4.0))
);
