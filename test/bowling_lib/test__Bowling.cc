#include "bowling.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE ("a new frame has a score of 0")
{
  Bowling::Frame f;
  REQUIRE(f.get_score() == 0);
}
TEST_CASE ("an open frame is scored properly")
{
  Bowling::Frame f;
  f.record_ball(3);
  f.record_ball(6);
  REQUIRE(f.get_score() == 9);
  REQUIRE_THROWS(f.record_ball(0));
}
TEST_CASE ("spare frames are scored properly")
{
  Bowling::Frame f;
  f.record_ball(3);
  f.record_ball(7);
  f.record_ball(5);
  REQUIRE(f.get_score() == 15);
}
TEST_CASE ("strike frames are scored properly")
{
  Bowling::Frame f;
  f.record_ball(10);
  f.record_ball(7);
  f.record_ball(2);
  REQUIRE(f.get_score() == 19);
  REQUIRE_THROWS(f.record_ball(0));
}
TEST_CASE ("it's possible to tell if a frame is accepting rolls")
{
  {
    Bowling::Frame f;
    REQUIRE(f.is_rollable() == true);
    f.record_ball(3);
    REQUIRE(f.is_rollable() == true);
    f.record_ball(5);
    REQUIRE(f.is_rollable() == false);
  }
  {
    Bowling::Frame f;
    REQUIRE(f.is_rollable() == true);
    f.record_ball(3);
    REQUIRE(f.is_rollable() == true);
    f.record_ball(7);
    REQUIRE(f.is_rollable() == true);
    f.record_ball(0);
    REQUIRE(f.is_rollable() == false);
  }
  {
    Bowling::Frame f;
    REQUIRE(f.is_rollable() == true);
    f.record_ball(10);
    REQUIRE(f.is_rollable() == true);
    f.record_ball(0);
    REQUIRE(f.is_rollable() == true);
    f.record_ball(0);
    REQUIRE(f.is_rollable() == false);
  }
}
TEST_CASE ("the game will not be complete")
{
  Bowling::Game g;
  REQUIRE(g.is_complete() == false);
}
TEST_CASE ("a new game has a score of 0")
{
  Bowling::Game g;
  REQUIRE(g.get_score() == 0);
}
TEST_CASE ("invalid number of pins has record_ball() throw an exception")
{
  Bowling::Game g;
  REQUIRE_THROWS(g.record_ball(-1));
  REQUIRE_THROWS(g.record_ball(11));
}
TEST_CASE ("this test will pass")
{ 
  REQUIRE(true);
}
