#pragma once
#include <cstdint>

namespace Bowling
{
  class Frame
  {
    public:
      Frame();
    public:
      int32_t get_score() const;
      void record_ball(int32_t num_pins);
      bool is_complete() const;
    private:
      int32_t m_score;
      int32_t m_num_rolls;
      bool m_is_complete;
  };
  class Game
  {
    public:
      bool is_complete() const;
      int32_t get_score() const;
      void record_ball(int32_t num_pins);
    private:
      int frames;

  };

  
}

