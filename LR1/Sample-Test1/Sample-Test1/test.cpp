#include "pch.h"
#include "parser.h"
parser my_parser(720, 1280);
TEST(TestCmd, clear_1) 
{
  string str = "0 ff ff ff";
  my_parser.parse(const_cast<char*>(str.c_str()));
  EXPECT_EQ(my_parser.my_answer.comm_id, 0);
  ASSERT_TRUE(my_parser.my_answer.check);
  EXPECT_EQ(my_parser.my_answer.R, 255);
  EXPECT_EQ(my_parser.my_answer.G, 255);
  EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, clear_2)
{
	string str = "0 ffff ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 0);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_pixel)
{
	string str = "1 50 50 00 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 1);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_pixel_2)
{
	string str = "1 5050 00 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 1);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_line)
{
	string str = "2 50 50 50 50 ff 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 2);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.x1, 50);
	EXPECT_EQ(my_parser.my_answer.y1, 50);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_line_2)
{
	string str = "2 50 50 5 50 50 ff 00 ff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 2);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.x1, 50);
	EXPECT_EQ(my_parser.my_answer.y1, 50);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
}
TEST(TestCmd, draw_rect)
{
	string str = "3 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 3);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_rect_2)
{
	string str = "3 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 3);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill)
{
	string str = "4 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 4);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_2)
{
	string str = "4 50 50 50 50 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 4);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_ellipse)
{
	string str = "5 50 50 20 30 00 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 5);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius_x, 20);
	EXPECT_EQ(my_parser.my_answer.radius_y, 30);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_ellipse_2)
{
	string str = "5 50 50 20 30 fff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 5);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius_x, 20);
	EXPECT_EQ(my_parser.my_answer.radius_y, 30);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_ellipse)
{
	string str = "6 50 50 20 30 ff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 6);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius_x, 20);
	EXPECT_EQ(my_parser.my_answer.radius_y, 30);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_ellipse_2)
{
	string str = "6 50 50 20 30 ff 00 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 6);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius_x, 20);
	EXPECT_EQ(my_parser.my_answer.radius_y, 30);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_circle)
{
	string str = "7 50 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 7);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 20);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_circle_2)
{
	string str = "750 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 7);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 20);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_circle)
{
	string str = "8 50 50 20 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id,8);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 20);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_circle_2)
{
	string str = "8 50 50 2000 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 8);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 20);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_round_rect)
{
	string str = "9 50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 9);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 10);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_round_rect_2)
{
	string str = "A 50 5050 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 10);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 10);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_round_rect)
{
	string str = "A 50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 10);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 10);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_fill_round_rect_2)
{
	string str = "A50 50 50 50 10 00 ff 00";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 10);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 50);
	EXPECT_EQ(my_parser.my_answer.y0, 50);
	EXPECT_EQ(my_parser.my_answer.h, 50);
	EXPECT_EQ(my_parser.my_answer.w, 50);
	EXPECT_EQ(my_parser.my_answer.radius, 10);
	EXPECT_EQ(my_parser.my_answer.R, 0);
	EXPECT_EQ(my_parser.my_answer.G, 255);
	EXPECT_EQ(my_parser.my_answer.B, 0);
}
TEST(TestCmd, draw_text)
{
	string str = "B 100 100 ff 00 ff 16 5 hello";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 11);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 100);
	EXPECT_EQ(my_parser.my_answer.y0, 100);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
	EXPECT_EQ(my_parser.my_answer.font, 16);
	EXPECT_EQ(my_parser.my_answer.length, 5);
	EXPECT_EQ(my_parser.my_answer.text, " hello");
}
TEST(TestCmd, draw_text_2)
{
	string str = "B 100 100 ff 00 ff 16 5hello";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 11);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 100);
	EXPECT_EQ(my_parser.my_answer.y0, 100);
	EXPECT_EQ(my_parser.my_answer.R, 255);
	EXPECT_EQ(my_parser.my_answer.G, 0);
	EXPECT_EQ(my_parser.my_answer.B, 255);
	EXPECT_EQ(my_parser.my_answer.font, 16);
	EXPECT_EQ(my_parser.my_answer.length, 5);
	EXPECT_EQ(my_parser.my_answer.text, " hello");
}
TEST(TestCmd, draw_image)
{
	string str = "C 100 100 200 200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 12);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 100);
	EXPECT_EQ(my_parser.my_answer.y0, 100);
	EXPECT_EQ(my_parser.my_answer.h, 200);
	EXPECT_EQ(my_parser.my_answer.w, 200);
}
TEST(TestCmd, draw_image_2)
{
	string str = "C 100 100 200200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 12);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.x0, 100);
	EXPECT_EQ(my_parser.my_answer.y0, 100);
	EXPECT_EQ(my_parser.my_answer.h, 200);
	EXPECT_EQ(my_parser.my_answer.w, 200);
}
TEST(TestCmd, set_orient)
{
	string str = "D 2";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 13);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.orientation, 2);
}
TEST(TestCmd, set_orient_2)
{
	string str = "D 200";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 13);
	ASSERT_TRUE(my_parser.my_answer.check);
	EXPECT_EQ(my_parser.my_answer.orientation, 2);
}
TEST(TestCmd, Get_Width)
{
	string str = "E";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 14);
	EXPECT_EQ(my_parser.my_answer.width, 1280);
	EXPECT_TRUE(my_parser.my_answer.check);
}
TEST(TestCmd, Get_Width_2)
{
	string str = "Eee";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 14);
	EXPECT_EQ(my_parser.my_answer.width, 1280);
	EXPECT_TRUE(my_parser.my_answer.check);
}
TEST(TestCmd, Get_Height)
{
	string str = "F";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 15);
	EXPECT_EQ(my_parser.my_answer.height, 720);
}
TEST(TestCmd, Get_Height_2)
{
	string str = "Fffff";
	my_parser.parse(const_cast<char*>(str.c_str()));
	EXPECT_EQ(my_parser.my_answer.comm_id, 15);
	EXPECT_EQ(my_parser.my_answer.height, 720);
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}