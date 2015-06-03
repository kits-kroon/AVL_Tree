#ifndef UNIT_H
#define UNIT_H

#include <string>
#include "unit.h"

using namespace std;

        /**
         * @class Unit
         * @brief Stores data for the unit class
         *
         * The Unit class has been designed to store relevant data
         * pertaining to that of a unit a University.
         *
         * @author Jake Kroon
         * @version 01
         * @date 01/04/2015
         *
         * @bug No bugs to my knowledge
         */

class Unit
{

    public:

                /**
                 * @brief Default constructor for class unit
                 *
                 * This constructor initialises a Unit class object with the default values
                 *
                 * @return void
                 */
        Unit();

                /**
                 * @brief Set the credit value
                 *
                 * Allows setting of the credit point value of a Unit object.
                 *
                 * @param cred - The credit point value of the unit as an unsigned integer
                 * @return void
                 */
        void SetCredits( unsigned cred );

                /**
                 * @brief Set the name of the unit
                 *
                 * Allows the setting of the unit name of a Unit object
                 *
                 * @param nam - The name of the unit for the unit object as a string
                 * @return void
                 */
        void SetName(string nam);

                /**
                 * @brief Set the UnitId
                 *
                 * Allows the setting of the unit Id of a Unit object
                 *
                 * @param nId - The unit Id for the unit object as a string
                 * @return void
                 */
        void SetId(string nId);

                /**
                 * @brief Get the Unit Name
                 *
                 * Allows the getting of a unit name for a Unit object
                 *
                 * @return name - The name of the unit as a constant string
                 */
        const string GetName() const;

                /**
                 * @brief Get the Unit Id
                 *
                 * Allows the getting of a unit id for a Unit object
                 *
                 * @return id - The id of the unit as a constant string
                 */
        const string GetId() const;

                /**
                 * @brief Get the credits
                 *
                 * Allows the getting of the credits for a Unit object
                 *
                 * @return credits - The credits of the unit as a constant integer
                 */
        const unsigned GetCredits() const;

    private:

        string name;      /** The name of the unit   */
        string id;        /** The id of the unit     */
        unsigned credits; /** The credis of the unit */
};

bool operator < (const Unit & lhs, const Unit & rhs);
bool operator == (const Unit & lhs, const Unit & rhs);
ostream & operator << (ostream & os, const Unit & aUnit);

#endif // UNIT_H
