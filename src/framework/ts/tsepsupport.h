/**
 * @file
 *
 * @brief Class for handling people game expansion packs.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#pragma once

#include "rzstring.h"
class TSEpSupport
{
public:
    /**
     * The product index. The 2005 Christmas stuff pack along with it's '06 re-release aren't counted.
     */
    enum eProductIndex: int {
        BaseGame = 0, /*!< Base game */
        University = 1, /*!< University Expansion Pack */
        Nightlife = 2, /*!< Nightlife Expansion Pack */
        OFB = 3, /*!< Open for Business Expansion Pack */
        Family = 4, /*!< Family Fun Stuff Pack */
        Glamour = 5, /*!< Glamour Life Stuff Pack */
        Pets = 6, /*!< Pets Expansion Pack */
        Seasons = 7, /*!< Seasons Expansion Pack */
        Celebration = 8, /*!< Celebration! Stuff Pack */
        Fashion = 9, /*!< H&M Fashion Stuff Pack */
        Vacation = 10, /*!< Bon Voyage Expansion Pack (macOS Super Collection) */
        Teenage = 11, /*!< Teen Style Stuff Pack */
        FreeTime = 12, /*!< FreeTime Expansion Pack */
        KitchenBath = 13, /*!< Kitchen & Bath Interior Design Stuff Pack */
        IKEA = 14, /*!< IKEA Home Stuff Pack */
        Apartment = 15, /*!< Apartment Life Expansion Pack */
        MansionGarden = 16, /*!< Mansion & Garden Stuff Pack (Windows Ultimate Collection) */
    };

    /**
     * Flags for indicating what expansion pack is installed.
     */
    enum eEPFlags: int {
        BaseGameF = 0x0, /*!< Base game */
        UniversityF = 0x2, /*!< University Expansion Pack */
        NightlifeF = 0x4, /*!< Nightlife Expansion Pack */
        OFBF = 0x8, /*!< Open for Business Expansion Pack */
        PetsF = 0x40, /*!< Pets Expansion Pack */
        SeasonsF = 0x80, /*!< Seasons Expansion Pack */
        VacationF = 0x400, /*!< Bon Voyage Expansion Pack (macOS Super Collection) */
    }

    const char* kSims2EXENameBaseProduct = "Sims2.exe"; /*!< File name of base game's Windows executable */
    const char* kSims2EXECurrentProduct = nullptr;
    const char* kSims2EXENameEP6 = "Sims2EP6.exe"; /*!< File name of Bon Voyage's Windows executable */

    int DetermineWhichEPContainsDataPath(cIGZString const&);
    static eProductIndex GetActiveCodeVersion() { return Vacation; };
    static eEPFlags GetActiveEPFlag() { return VacationF; };
    static eProductIndex GetActiveProductIndex() { return Vacation; };
    bool GetAppInfo(char const*, char*, unsigned long*, char*, unsigned long*, char*, unsigned long*, unsigned long*);
    eEPFlags GetEPFlagFromProductIndex(eProductIndex);
    void GetExeNameForHighestInstalledProductFromRegistry(char*);
    unsigned int GetInstalledEPS(); // mask()???
    int GetLatestProductIndex();
    bool IsEPInstalled(eEPFlags);
    bool IsEPInstalled(eProductIndex);
    unsigned int IsMoreAdvancedExpansionPackInstalled(char*, int*);
    cRZString IsUserDataPath(cIGZString const&);
    bool UpdateEPInfo(char*, char*, int);


private:
    void GetInstalledEPPaths(char const*, char**&, int*);
};
