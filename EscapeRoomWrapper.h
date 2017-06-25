#ifndef ESCAPEROOMWRAPPER_H
#define ESCAPEROOMWRAPPER_H

#include <string>
#include <iostream>
#include "EscapeRoom.h"


namespace mtm{
namespace escaperoom {

    class EscapeRoomWrapper{
    private:
        char* name;
        int level;
        int maxTime;
        int maxParticipants;
        int avgRate;
        int votes;

        // Calculates and returns the Power value of a room.
        // The value is equal to maxTime*level/maxParticipants.
        int calculatePower() const;

        /**Checks if escapeTime is within legal boundries(over 30 and under 90).
         *
         * @param escapeTime- the time we check.
         * @return true if the value is legal, false otherwise.
         */
        bool checkEscapeTime(const int& escapeTime) const

        /**Checks if level is within legal boundries(over 1 and under 10).
         *
         * @param level- the level we check.
         * @return true if the value is legal, false otherwise.
         */
        bool checkLevel(const int& level) const

        /**Checks if maxParticipants is within legal boundries(over 1).
         *
         * @param maxParticipants- the participants we check.
         * @return true if the value is legal, false otherwise.
         */
        bool checkMaxParticipants(const int& maxParticipants)const


    public:
        // Constructs a new Escape Room with the specified data.
        //
        // @param name : the name of the escape room.
        // @param escapeTime : the maximal escape time allowed in the room.
        // @param level : the level of the escape room.
        // @param maxParticipants: the maximal participants allowed in the room.
        // The rest of the room's data is initialized as described in the exercise sheet.
        // @throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(char* name, const int& escapeTime, const int& level, const int& maxParticipants);

        // Constructs a new Escape Room with the specified data.
        //
        // @param name : the name of the enigma.
        // @param level : the level of the escape room.
        // The rest of the room's data is initialized as described in the exercise sheet.
        // @throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(char* name, const int& level);

        //copy constructor
        //
        //@param room : the room to be copied.
        //@throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(const EscapeRoomWrapper& room);

        //assignment operator
        //
        //@param room : the room to be assigned.
        EscapeRoomWrapper& operator=(const EscapeRoomWrapper& room);

        // Comparison operators for Escape Rooms. rooms are compared as described in
        // the exercise sheet.
        //
        // @param room : the right-hand side operand.
        bool operator==(const EscapeRoomWrapper& room) const;
        bool operator!=(const EscapeRoomWrapper& room) const;
        bool operator<(const EscapeRoomWrapper& room) const;
        bool operator>(const EscapeRoomWrapper& room) const;

        bool operator<=(const EscapeRoomWrapper& room) const = delete;
        bool operator>=(const EscapeRoomWrapper& room) const = delete;

        // return the level of the Escape Room.
        //
        int level() const;

        // the method changes the rate according to the rate given.
        //
        // @param newRate : the new rate accepted to the room.
        //@throws EscapeRoomIllegalRateException in case of illegal rate parameter.
        void rate(const int& newRate);

        // Destructor for EscapeRoomWrapper
        ~EscapeRoomWrapper();

        // Prints the data of the Room in the following format:
        //
        //     "<name> (<maxTime>/<level>/<maxParticipants>)"
        //
        // @param output : the output stream to which the data is printed.
        // @param room : the room whose data is printed.
        friend std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);

        //Function returns the name of the EscapeRoom.
        //
        std::string getName() const;

        //Function returns the rate of the EscapeRoom.
        //
        double getRate() const;

        //Function returns the maximum escape time of the EscapeRoom.
        //
        int getMaxTime() const;

        //Function returns the number of participants allowed in the EscapeRoom.
        //
        int getMaxParticipants() const;

    };

    std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);
} // end of namespace eascaperoom
} // end of namespace mtm


#endif //ESCAPEROOMWRAPPER_H
