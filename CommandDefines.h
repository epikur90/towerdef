//------------------------------------------------------------------------------
// CommandDefines.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDDEFINES_H
#define COMMANDDEFINES_H

//------------------------------------------------------------------------------
// Enum with Return States

typedef enum CmdReturn
{
  EXIT = -3,
  ERR_CMD = -1,
  ERR_USE = -2,
  ERR_EMPTY = 0,
  ERR_TYPE = 0,
  CMD_SUC = 0
} CmdReturn;

//------------------------------------------------------------------------------
// Enum with CommandStates

typedef enum Cmds
{
  SHOW = 0, NEXT, SHOP, STATS, BUY, QUIT, CMD_COUNTER
} Cmds;

#endif //COMMANDDEFINES_H
