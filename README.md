# Initial game modeling

Creature ( abstract )
    Player
    NPC
    Monster
        Slime
        Bat

Event
    Cutscene
    Battle
    Map_update

main()
{
    main_menu( switch )
        START
        LOAD
        INFO (instructions if needed || art || about me)
}

START creates a new Game_Loop
{
    player: position inventory
    map   : updated on triggers
    enemy_parties: chance, totalnumberOfEach
    encounter_frequency

    waiting loop
    {
        PAUSE  -> #define macro
        inventory_invoke -> player
        interact -> map_interact_available()
        walk -> event trigger
    }
}