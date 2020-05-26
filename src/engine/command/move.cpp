#include "engine/command/move.h"

void MoveRightCommand::execute(Player& entity, float& dt)
{
    entity.move( entity.getSpeed()*dt, 0, Player::RIGHT_MOVE, "walk-right");
}

void MoveLeftCommand::execute(Player& entity, float& dt)
{
    entity.move( -entity.getSpeed()*dt, 0, Player::LEFT_MOVE, "walk-left");
}

void MoveUpCommand::execute(Player& entity, float& dt)
{
    entity.move( 0, -entity.getSpeed()*dt, Player::UP_MOVE, "walk-up");
}

void MoveDownCommand::execute(Player& entity, float& dt)
{
    entity.move( 0, entity.getSpeed()*dt, Player::DOWN_MOVE, "walk-down");
}