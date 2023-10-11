#include <iostream>
#include <string>
#include <list>
#include <Windows.h>
using namespace std;

class JJKCharacter {
public:
    string name;
    string curseTechnique;

    JJKCharacter(const string& name, const string& curseTechnique) : name(name), curseTechnique(curseTechnique) {}
};

class CursedCollection {
public:
    list<JJKCharacter> characterList;
    list<JJKCharacter>::iterator currentCharacter;
    int cursedCoins = 0;
    int summonCount = 0;

    void summonCharacter(const string& name, const string& curseTechnique) {
        characterList.emplace_back(name, curseTechnique);
        if (characterList.size() == 1) {
            currentCharacter = characterList.begin();
        }
    }

    void insertCursedCoins(int coins) {
        cursedCoins += coins;
    }

    void summon() {
        if (!characterList.empty()) {
            while (cursedCoins > 0) {
                cout << "Now summoning: " << currentCharacter->name << " with " << currentCharacter->curseTechnique << " Curse Technique #" << summonCount << endl;
                Sleep(2000);
                nextSummon();
            }
            cout << "Summoning Ended, Insert more Cursed Coins!" << endl;
        } else {
            cout << "Cursed Collection is empty." << endl;
        }
    }

    void nextSummon() {
        if (!characterList.empty()) {
            ++currentCharacter;
            if (currentCharacter == characterList.end()) {
                currentCharacter = characterList.begin();
                cursedCoins--;
                summonCount++;
            }
        }
    }
};

int main() {
    CursedCollection jjkCollection;

    jjkCollection.summonCharacter("Yuji Itadori", "Divergent Fist");
    jjkCollection.summonCharacter("Megumi Fushiguro", "Ten Shadows Technique");
    jjkCollection.summonCharacter("Nobara Kugisaki", "Straw Doll Technique");
    jjkCollection.summonCharacter("Satoru Gojo", "Limitless Cursed Technique");
    jjkCollection.summonCharacter("Maki Zenin", "Swordsmanship");
    jjkCollection.summonCharacter("Panda", "Cursed Corpse");
    jjkCollection.summonCharacter("Toge Inumaki", "Cursed Speech");
    jjkCollection.summonCharacter("Mai Zenin", "Cursed Tools");

    jjkCollection.insertCursedCoins(5);
    jjkCollection.summon();
}
