#include "command.h"

Command::Command(int _fromX, int _fromY, int _toX, int _toY, Player _player)
    : m_fromX(_fromX),
      m_fromY(_fromY),
      m_toX(_toX),
      m_toY(_toY),
      m_player(_player)
{}
