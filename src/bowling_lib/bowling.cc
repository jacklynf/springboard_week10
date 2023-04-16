#include "bowling.h"
#include <stdexcept>

namespace Bowling
{
  Frame::Frame()
    : m_score(0),
    m_num_rolls(0),
    m_is_complete(true)
    { }
  
  int32_t Frame::get_score() const
  { return m_score; }

  bool Frame::is_complete ()
  { 
    return m_is_complete;
  }

  void Frame::record_ball (int32_t num_pins)
  {
    if (m_num_rolls == 3)
    {
      throw std::logic_error("cannot have more than 3 balls in a frame");
    }
    if ((m_num_rolls == 2) && (m_score < 10))
    {
      throw std::logic_error("cannot have 3 balls in open frame"); 
    }
    m_num_rolls++; 
    m_score += num_pins;
  }
    
}


namespace Bowling
{
  bool Game::is_complete () const
  { return false; }

  int32_t Game::get_score () const
  { return 0; }

  void Game::record_ball (int32_t num_pins)
  {
    if ( (num_pins < 0) || (num_pins > 10) )
      {throw std::invalid_argument("invalid number of pins"); } 
  }
}

