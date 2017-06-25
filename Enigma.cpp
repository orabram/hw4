#include <iostream>
#include <string>
#include <set>
#include "Enigma.h"

namespace mtm {
    namespace escaperoom {

        class Enigma { //?
        private:
            string name;
            Difficulty difficulty;
            int numOfElements;

        public:
            Enigma(const std::string &name, const Difficulty &difficulty,
                   const int &numOfElements)
            {
                this->numOfElements = numOfElements;
                this->difficulty = difficulty;
                this->name = name;
            }
            Enigma(const Enigma& enigma) = default
            {
                this->numOfElements = enigma.numOfElements;
                this->difficulty = enigma.difficulty;
                this->name = enigma.name;
            }
            Enigma& operator=(const Enigma& enigma) = default //Same as copy c'tor?
            {
                this->numOfElements = enigma.numOfElements;
                this->difficulty = enigma.difficulty;
                this->name = enigma.name;
            }
            bool operator==(const Enigma& enigma) const
            {
                if(enigma.name == this->name && this->difficulty ==
                                                        enigma.difficulty)
                {
                    return true;
                }
                return false;
            }
            bool operator!=(const Enigma& enigma) const
            {
                if(enigma.name == this->name && this->difficulty ==
                                                enigma.difficulty)
                {
                    return false;
                }
                return true;
            }
            bool operator<(const Enigma& enigma) const
            {
                if(this->difficulty < enigma.difficulty)
                {
                    return true;
                }
                return false;
            }
            bool operator>(const Enigma& enigma) const
            {
                if(this->difficulty > enigma.difficulty)
                {
                    return true;
                }
                return false;
            }
            bool areEqualyComplex(const Enigma& enigma) const
            {
                if(enigma.difficulty == this->difficulty &&
                        this->numOfElements == enigma.numOfElements)
                {
                    return true;
                }
                return false;
            }
            Difficulty getDifficulty() const
            {
                return this->difficulty;
            }
            string getName() const
            {
                return this->name;
            }
            std::ostream& operator<<(std::ostream& output, const Enigma& enigma)
            {
                output << enigma.name << " (" << enigma.difficulty << ") "
                       << enigma.numOfElements;
                return output;
            }

        };
    }
}