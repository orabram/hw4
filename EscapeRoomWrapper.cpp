#include <iostream>
#include <cstring>
#include "Exceptions.h"
#include "EscapeRoomWrapper.h"

 //EXCEPTIONS WILL BE ADDED LATER

namespace mtm {
    namespace escaperoom {

        class EscapeRoomWrapper {
        private:
            char *name;
            int level;
            int maxTime = 60;
            int maxParticipants = 6;
            int avgRate = 0;
            int votes = 0;

            int calculatePower() const {
                return ((this->level * this->maxTime) / this->maxParticipants);
            }

            bool checkEscapeTime(const int &escapeTime) const {
                if (escapeTime >= 30 && escapeTime <= 90)
                    return true;
                return false;
            }

            bool checkLevel(const int &level) const {
                if (level >= 1 && level <= 10)
                    return true;
                return false;
            }

            bool checkMaxParticipants(const int &maxParticipants) const {
                if (maxParticipants > 1)
                    return true;
                return false;
            }

        public:
            EscapeRoomWrapper::EscapeRoomWrapper(char *name,
                                                 const int &escapeTime,
                                                 const int &level,
                                                 const int &maxParticipants) {
                if (name == NULL || !checkEscapeTime(escapeTime) ||
                    !checkLevel(level)
                    || !checkMaxParticipants(maxParticipants)) {
                    throw; //InvalidParams
                }
                this->level = level;
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
                this->maxParticipants = maxParticipants;
                this->maxTime = escapeTime;
                this->level = level;
                if (this->name == NULL) {
                    throw; //EscapeRoomMemoryProblems
                }
            }

            EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &level) {
                if (name == NULL || !checkLevel(level)) {
                    throw; //InvalidParams
                }
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
                this->level = level;
                if (this->name == NULL) {
                    throw; //EscapeRoomMemoryProblems
                }
            }

            EscapeRoomWrapper::EscapeRoomWrapper(
                    const EscapeRoomWrapper &room) {
                this->level = room.level;
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, room.name);
                this->maxParticipants = room.maxParticipants;
                this->maxTime = room.maxTime;
                this->level = room.level;
                if (this->name == NULL) {
                    throw; //EscapeRoomMemoryProblems
                }
            }

            EscapeRoomWrapper &operator=(
                    const EscapeRoomWrapper &room) /*Not clear what should I do- I'm copying the copy c'tor for now.*/
            {
                this->level = room.level;
                strcpy(this->name, room.name);
                this->maxParticipants = room.maxParticipants;
                this->maxTime = room.maxTime;
                this->level = room.level;
            }

            bool operator==(const EscapeRoomWrapper &room) const {
                int power1 = this->calculatePower();
                int power2 = room.calculatePower();
                if (power1 == power2) {
                    if (!strcmp(room.name, this->name)) {
                        return true;
                    }

                }
                return false;
            }

            bool operator!=(const EscapeRoomWrapper &room) const {
                int power1 = this->calculatePower();
                int power2 = room.calculatePower();
                if (power1 == power2) {
                    if (!strcmp(room.name, this->name)) {
                        return false;
                    }

                }
                return true;
            }

            bool operator<(const EscapeRoomWrapper &room) const {
                int power1 = this->calculatePower();
                int power2 = room.calculatePower();
                if (power1 < power2) {
                    return true;
                }
                return false;
            }

            bool operator>(const EscapeRoomWrapper &room) const {
                int power1 = this->calculatePower();
                int power2 = room.calculatePower();
                if (power1 > power2) {
                    return true;
                }
                return false;
            }

            int level() const //?
            {
                return this->level;
            }

            void rate(const int &newRate) {
                if (newRate < 0 || newRate > 5) {
                    throw; //IllegalRate
                }
                this->votes++;
                this->avgRate += ((newRate - this->avgRate) / this->votes);
            }

            ~EscapeRoomWrapper() {
                delete[] (this->name);
            }

            std::string getName() const {
                return this->name;
            }

            double getRate() const {
                return this->avgRate;
            }

            int getMaxTime() const {
                return this->maxTime;
            }

            int getMaxParticipants() const {
                return this->maxParticipants;
            }

            std::ostream &operator<<(std::ostream &output,
                                     const EscapeRoomWrapper &room) {
                output << room.name << " (" << room.maxTime << "/" << room.level
                       << "/"
                       << room.maxParticipants << ")";
                return output;
            }

        };
    }
}