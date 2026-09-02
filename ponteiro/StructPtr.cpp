#include <print>
#include <iostream>
#include <cstring>
#include <vector>

struct Pokemon{
    std::string name;
    std::string type;
    int level;
    int hp;

    void LevelUP(int points){
        hp += points;
    }

    Pokemon(){};

    Pokemon(std::string n, std::string t, int l, int h) : name(n), type(t), level(l), hp(h) {}
};

struct Trainer{
    std::string name;
    std::string city;
    std::vector<Pokemon> Pokemons;

    void PrintPokemons()
    {
        for (const auto& pokemon : Pokemons){
            std::println("Name: {}", pokemon.name);
            std::println("Type: {}", pokemon.type);
            std::println("Level: {}", pokemon.level);
            std::println("HP: {}", pokemon.hp);
            std::println("");
        }
    }
};

int main(void){

    Pokemon* ptrPokemon = new Pokemon;
    
    ptrPokemon->name = "Snorlax";
    ptrPokemon->type = "Normal";
    ptrPokemon->level = 50;
    ptrPokemon->hp = 160;

    // std::println(">> Pokemon data: ");
    // std::println("Name: {}", ptrPokemon->name);
    // std::println("Type: {}", ptrPokemon->type);
    // std::println("Level: {}", ptrPokemon->level);
    // std::println("HP: {}", ptrPokemon->hp);

    Pokemon* ptrPokemon2 = new Pokemon("Squirtle", "Water", 20, 60);
    Pokemon* ptrPokemon3 = new Pokemon("Gardenvoir", "Psychic", 50, 130);

    Trainer* trainer = new Trainer;
    trainer->name = "Ash";
    trainer->city = "Pallet Town";
    trainer->Pokemons.push_back(*ptrPokemon);
    trainer->Pokemons.push_back(*ptrPokemon2);
    trainer->Pokemons.push_back(*ptrPokemon3);

    std::println(">> Dados do Treinador:");
    std::println("Name: {}", trainer->name);
    std::println("City: {}", trainer->city);
    std::println("\n>> Pokemons: \n");
    trainer->PrintPokemons();

    std::cin.get();
    return 0;
}