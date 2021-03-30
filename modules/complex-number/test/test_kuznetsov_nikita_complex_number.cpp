// Copyright 2021 Kuznetsov Nikita

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Kuznetsov_Nikita_ComplexNumberTest, Can_Assign_Element) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z1(re, im);

    ComplexNumber z2(z1);
    bool sw = z1 == z2;

    ASSERT_TRUE(sw);
}

TEST(Kuznetsov_Nikita_ComplexNumberTest, Can_Sum_Elements) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(1.0, 3.0);

  ComplexNumber sum = z1 + z2;

  EXPECT_EQ(sum, ComplexNumber(4.0, 5.0));
}

TEST(Kuznetsov_Nikita_ComplexNumberTest, Can_Multiply_Elements) {
  ComplexNumber z1(3.0, 2.0);
  ComplexNumber z2(1.0, 3.0);

  ComplexNumber result = z1 * z2;

  EXPECT_EQ(result, ComplexNumber(-3.0, 11.0));
}
