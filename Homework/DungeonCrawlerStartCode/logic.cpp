#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream inFS;
    inFS.open(fileName);
    char location;

    if(!inFS.is_open())
    {
        return nullptr;
    }

    inFS >> maxRow;
    if(inFS.fail())
    {
        return nullptr;
    }
    inFS >> maxCol;
    if(inFS.fail())
    {
        return nullptr;
    }
    inFS >> player.row;
    if(inFS.fail())
    {
        return nullptr;
    }
    inFS >> player.col;
    if(inFS.fail())
    {
        return nullptr;
    }
    if(maxRow > INT32_MAX/static_cast<double>(maxCol))
        return nullptr;
    if(maxCol > INT32_MAX/static_cast<double>(maxRow))
        return nullptr;

    if(maxRow*maxCol>INT32_MAX)
        return nullptr;
    if(maxCol <=0 || maxRow <=0)
        return nullptr;
    if(player.row < 0 || player.row >= maxRow || player.col < 0 || player.col >= maxCol)
        return nullptr;

    //making 2d array of the dungeon
    char** dungeon = createMap(maxRow, maxCol);
    
  


    //mark player location with the player symbol
    bool exit = false;
    for(int row = 0; row < maxRow; row++)
    {
        for(int col = 0; col< maxCol; col++)
        {
            inFS >> location;
            if(location != TILE_AMULET && location != TILE_DOOR && location != TILE_EXIT && location != TILE_MONSTER && location != TILE_OPEN && location != TILE_PILLAR && location != TILE_TREASURE)
                return nullptr;
            if(row == player.row && col == player.col)
            {
                dungeon[row][col] = TILE_PLAYER;
            }
            else
            {
                if(inFS.fail())
                {
                    return nullptr;
                }
                dungeon[row][col] = location;
                if(location == TILE_DOOR || location == TILE_EXIT)
                    exit = true;
            }  
        }
    }
    char extra;
    inFS>> extra;
    if(!inFS.fail())
    {
        if(extra == TILE_AMULET || extra == TILE_DOOR || extra == TILE_EXIT || extra == TILE_MONSTER || extra == TILE_OPEN || extra == TILE_PILLAR || extra == TILE_TREASURE)
            return nullptr;
    }
    if(!exit)
        return nullptr;

    inFS.close();
    return dungeon;
    
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input == MOVE_UP)
    {
        nextRow--;
    }
    if(input == MOVE_DOWN)
    {
        nextRow++;
    }
    if(input == MOVE_RIGHT)
    {
        nextCol++;
    }
    if(input == MOVE_LEFT)
    {
        nextCol--;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    bool fail = false;
    char** dungeon = new char*[maxRow];
    for(int i = 0; i < maxRow; i++)
    {
        dungeon[i] = new char[maxCol];
        if (dungeon[i] == nullptr) { // failed to allocate
            fail = true;
        }
    }
    if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
        for (int i=0; i < maxCol; ++i) {
            delete [] dungeon[i]; // deleting nullptr is not a problem
        }
        delete [] dungeon; // delete array of pointers
        return nullptr;
    }

    for(int row = 0; row < maxRow; row++)
    {
        for(int col = 0; col< maxCol; col++)
        {
            dungeon[row][col] = TILE_OPEN;
        }
    }
    
    return dungeon;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map == nullptr)
        maxRow = 0;
    if(maxRow <= 0 || maxRow>INT32_MAX)
    {
        delete[] map;
        map = nullptr;
        maxRow = 0;
    }
    for(int i = 0; i < maxRow; i++)
    {
        delete[] map[i];
    }
    delete [] map;
    map = nullptr;
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    //int status = 0;
    int new_maxRow = 2 * maxRow;
    int new_maxCol = 2* maxCol;
    bool fail = false;

    if(map == nullptr || maxRow < 1 || maxCol < 1)
        return nullptr;

    char ** resized_map = new char*[new_maxRow];
    for(int i = 0; i < new_maxRow; i++)
    {
        resized_map[i] = new char[new_maxCol];
        if (resized_map[i] == nullptr) { // failed to allocate
            fail = true;
        }
    }
    if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
        for (int i=0; i < new_maxCol; ++i) {
            delete [] resized_map[i]; // deleting nullptr is not a problem
        }
        delete [] resized_map; // delete array of pointers
        return nullptr;
    }

    //A
    for(int row = 0; row < maxRow; row++)
    {
        for(int col = 0; col < maxCol; col++)
        {
            resized_map[row][col] = map[row][col];
        }
    }

    //B
    for(int row = 0; row < maxRow; row++)
    {
        for(int col = maxCol; col < new_maxCol; col++)
        {
            resized_map[row][col] = map[row][col-maxCol];
            if(map[row][col-maxCol] == TILE_PLAYER)
            {
                resized_map[row][col] = TILE_OPEN;
            }

        }
    }



    //C
    for(int row = maxRow; row < new_maxRow; row++)
    {
        for(int col = 0; col < maxCol; col++)
        {
            resized_map[row][col] = map[row-maxRow][col];
            if(map[row-maxRow][col] == TILE_PLAYER)
            {
                resized_map[row][col] = TILE_OPEN;
            }

        }
    }


    //D
    for(int row = maxRow; row < new_maxRow; row++)
    {
        for(int col = maxCol; col < new_maxCol; col++)
        {
            resized_map[row][col] = map[row-maxRow][col-maxCol];
            if(map[row-maxRow][col-maxCol] == TILE_PLAYER)
            {
                resized_map[row][col] = TILE_OPEN;
            }

        }
    }

    deleteMap(map, maxRow);
    maxRow = new_maxRow;
    maxCol = new_maxCol;
    return resized_map;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status = 0;
    if(nextRow >= maxRow || nextCol >= maxCol)
    {
        status = STATUS_STAY;
        nextRow = player.row;
        nextCol = player.col;
        return status;
    }
    else if(nextRow < maxRow && nextCol < maxCol)
    {
        if(player.col == 0)
        {
            if(nextCol == player.col - 1)
            {
                status = STATUS_STAY;
                nextCol = player.col;
                nextRow = player.row;
                return status;
            }
        }
        if(player.row == 0)
        {
            if(nextRow == player.row - 1)
            {
                status = STATUS_STAY;
                nextCol = player.col;
                nextRow = player.row;
                return status;
            }
        }
        if(map[nextRow][nextCol] == TILE_MONSTER || map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == '|')
        {
            status = STATUS_STAY;
            nextRow = player.row;
            nextCol = player.col;
            return status;
            
        }
        else if(map[nextRow][nextCol] == TILE_TREASURE)
        {
            status = STATUS_TREASURE;
            player.treasure++;
        }
        else if(map[nextRow][nextCol] == TILE_AMULET)
        {
            status = STATUS_AMULET;
        }
        else if(map[nextRow][nextCol] == TILE_DOOR)
        {
            status = STATUS_LEAVE;
        }
        else if(map[nextRow][nextCol] == TILE_EXIT)
        {
            if(player.treasure >= 1)
            {
                status = STATUS_ESCAPE;
            }
            else if(player.treasure < 1)
            {
                status = STATUS_STAY;
                nextCol = player.col;
                nextRow = player.row;
                return status;
            }
        }
        else if(map[nextRow][nextCol] == TILE_OPEN)
        {
            status = STATUS_MOVE;
        }

    }
    

    map[player.row][player.col] = TILE_OPEN; //player's old position
    player.row = nextRow;
    player.col = nextCol;
    map[nextRow][nextCol] = TILE_PLAYER;

    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    bool killed = false;

    int row = player.row-1;
    int col = player.col;
    //Up
    

    while(row > 0 && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
    {
        row--;
    }
    if(row < 0)
        row = 0;
    if(map[row][col] == TILE_MONSTER)
    {
        map[row + 1][col] = TILE_MONSTER;
        map[row][col] = TILE_OPEN;
        if(row != 0)
        {
            while(row > 0 && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
            {   
                row--;
            }
            if(row < 0)
                row = 0;
            if(map[row][col] == TILE_MONSTER)
            {
                map[row + 1][col] = TILE_MONSTER;
                map[row][col] = TILE_OPEN;
            }
        }
    }

    //DOWN
    row = player.row+1;
    col = player.col;
    
    while(row < maxRow && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
    {
        row++;
    }
    if(row >= maxRow)
        row = maxRow-1;
    if(map[row][col] == TILE_MONSTER)
    {
        map[row - 1][col] = TILE_MONSTER;
        map[row][col] = TILE_OPEN;
        if(row != maxRow-1)
        {
            while(row<maxRow)
            {
                while(row < maxRow && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
                {   
                    row++;
                }
                if(row >= maxRow)
                    row = maxRow-1;
                if(map[row][col] == TILE_MONSTER)
                {
                    map[row - 1][col] = TILE_MONSTER;
                    map[row][col] = TILE_OPEN;
                }
                row++;
            }
            
        }
    }

    //LEFT
    row = player.row;
    col = player.col-1;
    while(col > 0 && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
    {
        col--;
    }
    if(col < 0)
        col = 0;
    if(map[row][col] == TILE_MONSTER)
    {
        map[row][col+1] = TILE_MONSTER;
        map[row][col] = TILE_OPEN;
        if(col != 0)
        {
            while(col > 0 && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
            {   
                col--;
            }
            if(col < 0)
                col = 0;
            if(map[row][col] == TILE_MONSTER)
            {
                map[row][col+1] = TILE_MONSTER;
                map[row][col] = TILE_OPEN;
            }
        }
    }

    //RIGHT
    row = player.row;
    col = player.col+1;
    
    while(col < maxCol && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
    {
        col++;
    }
    if(col >= maxCol)
        col = maxCol-1;
    if(map[row][col] == TILE_MONSTER)
    {
        map[row][col-1] = TILE_MONSTER;
        map[row][col] = TILE_OPEN;
        if(col != maxCol-1)
        {
            
            while(col < maxCol && map[row][col] != TILE_PILLAR && map[row][col] != TILE_MONSTER)
            {   
                col++;
            }
            if(col >= maxCol)
                col = maxCol-1;
            if(map[row][col] == TILE_MONSTER)
            {
                map[row][col-1] = TILE_MONSTER;
                map[row][col] = TILE_OPEN;
            }
        }
    }

    if(map[player.row][player.col] == TILE_MONSTER)
    {
        killed = true;
    }

    return killed;
}
