#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
using namespace std;

class QuantumTraveller
{
public:
    string travellerName;
    int currentDimensionId;

    int energyLevel = 100;

    QuantumTraveller(string TravellerName, int CurrentDimensionId)
    {
        travellerName = TravellerName;
        currentDimensionId = CurrentDimensionId;
    };

    void travelToDimension(int dimensionId, list<Dimensions>)
    {
        currentDimensionId = dimensionId;
    }

private:
    string currentDimensionKey;
};

class Dimension
{
public:
    int dimensionID;
    string dimensionName;

    // list<string> attributes;

    Dimension(int DimensionID, string DimensionName)
    {
        dimensionID = DimensionID;
        dimensionName = DimensionName;
        // for (auto attribute : Attributes)
        // {
        //     attributes.push_back(attribute);
        // }
    };

    string joinDimension(QuantumTraveller &traveller)
    {
        string travellerKey = "null";
        while (true)
        {
            bool keyGenCheck = false;
            travellerKey = generateRandomTravellerKey(256);
            for (auto &traveller : travellers)
            {
                if (traveller.second == travellerKey)
                {
                    keyGenCheck = true;
                }
            }
            if (keyGenCheck)
            {
                continue;
            }
            else
            {
                break;
            }
        };

        travellers[&traveller] = travellerKey;
        return travellerKey;
    }

    bool leaveDimension(string travellerKey)
    {
        for (auto &traveller : travellers)
        {
            if (traveller.second == travellerKey && traveller.first->currentDimensionId == dimensionID)
            {
                travellers.erase(traveller.first);
                return true;
            }
        }
        return false;
    }

private:
    map<QuantumTraveller *, string> travellers;

    string generateRandomTravellerKey(size_t length)
    {
        random_device rd;
        mt19937 gen(rd());
        string str("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

        shuffle(str.begin(), str.end(), gen);

        return str.substr(0, length);
    }
};

int main()
{
    //     Create three dimensions with unique characteristics:
    //    - Dimension 1: Time-Warp Zone
    //      - Attributes: Speed, Time Manipulation, Time Loops

    //    - Dimension 2: Cyberspace
    //      - Attributes: Virtual Reality, Holographic Interfaces, AI Companions

    //    - Dimension 3: Bio-Morphic Gardens
    //      - Attributes: Living Plants, Shape-Shifting Flora, Healing Atmosphere

    Dimension dimension1(1, "Time-Warp Zone");
    Dimension dimension2(2, "Cyberspace");
    Dimension dimension3(3, "Bio-Morphic Gardens");
    list<Dimension *> dimensions;
    dimensions.push_back(&dimension1);
    dimensions.push_back(&dimension2);
    dimensions.push_back(&dimension3);

    QuantumTraveller ChronoPilot("ChronoPilot", 1);

    // cout << dimension1.joinDimension(ChronoPilot) << endl;

    // cout << dimension1.leaveDimension(dimension1.travellers[&ChronoPilot]) << endl;
}