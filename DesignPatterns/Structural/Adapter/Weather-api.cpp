#include <iostream>

using namespace std;

class WeatherService
{
public:
    virtual void getTemp() = 0;

    virtual ~WeatherService() {}
};

class ThirdPartyWeatherAPI
{
public:
    void fetchTemperature()
    {
        cout << "Temperature: 30 C" << endl;
    }
};

class WeatherAdapter : public WeatherService
{
private:
    ThirdPartyWeatherAPI& thirdPartyWeatherAPI;

public:
    WeatherAdapter(ThirdPartyWeatherAPI& thirdPartyWeatherAPI)
        : thirdPartyWeatherAPI(thirdPartyWeatherAPI)
    {
    }

    void getTemp() override
    {
        thirdPartyWeatherAPI.fetchTemperature();
    }
};

void showTemperature(WeatherService* weatherService)
{
    weatherService->getTemp();
}

int main()
{
    ThirdPartyWeatherAPI weatherAPI;

    WeatherAdapter adapter(weatherAPI);

    showTemperature(&adapter);

    return 0;
}
