#include "engine/command/sprint_command.h"

SprintCommand::SprintCommand(){ }

SprintCommand::~SprintCommand(){ }

void SprintCommand::execute(GameObject& gameObject)
{
    gameObject.getPhysics()->_speed = 80;
}