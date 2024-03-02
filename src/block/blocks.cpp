#include "block.h"
#include "position/position.h"

class OBlock : public Block {
  public:
    OBlock() {
      id = 4;
      // cells[0] = {
      //   Position(0,0),
      //   Position(0,1),
      //   Position(1,0),  
      //   Position(1,1)
      // };
      // move(0,4);
    }
};