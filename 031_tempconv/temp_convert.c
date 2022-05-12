#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInList(const char *str, const char *strings[]) {
    for (; *strings != NULL; strings++)
        if (strcmp(str, *strings) == 0)
            return true;
    return false;
}

#if 0
bool isInList(const char *str, const char *strings[] ) {
    return *strings && (!strcmp(str, *strings) || isList(str, strings + 1));
}
#endif


bool celsiusIsScale(const char *str) {
    const char *celsiusStrings[] = { "C", "°C", "c", "Celsius", "celsius", NULL };
    return isInList(str, celsiusStrings);
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double celsiusFromKelvin(double kelvin) {
    return kelvin - 273.15;
}


bool fahrenheitIsScale(const char *str) {
    const char *fahrenheitStrings[] = { "F", "°F", "f", "Fahrenheit", "fahrenheit", NULL };
    return isInList(str, fahrenheitStrings);
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

double fahrenheitFromKelvin(double kelvin) {
    return kelvin * 9/5 - 459.67;
}


bool kelvinIsScale(const char *str) {
    const char *kelvinStrings[] = { "K", "k", "Kelvin", "kelvin", NULL };
    return isInList(str, kelvinStrings);
}

double kelvinToKelvin(double kelvin) {
    return kelvin;
}

double kelvinFromKelvin(double kelvin) {
    return kelvin;
}


bool rankineIsScale(const char *str) {
    const char *rankineStrings[] = { "R", "°R", "r", "Rankine", "rankine", NULL };
    return isInList(str, rankineStrings);
}

double rankineToKelvin(double rankine) {
    return rankine * 5 / 9;
}

double rankineFromKelvin(double kelvin) {
    return kelvin * 9 / 5;
}


bool delisleIsScale(const char *str) {
    const char *delisleStrings[] = { "De", "de", "°De", "Delisle", "delisle", NULL };
    return isInList(str, delisleStrings);
}

double delisleToKelvin(double delisle) {
    return 373.15 - delisle * 2/3;
}

double delisleFromKelvin(double kelvin) {
    return (373.15 - kelvin) * 3/2;
}


bool newtonIsScale(const char *str) {
    const char *newtonStrings[] = { "N", "n", "°N", "Newton", "newton", NULL };
    return isInList(str, newtonStrings);
}

double newtonToKelvin(double newton) {
    return newton * 100/33 + 273.15;
}

double newtonFromKelvin(double kelvin) {
    return (kelvin - 273.15) * 33/100;
}


struct TemperatureScale {
    bool (*isScale)(const char *str);
    double (*toKelvin)(double);
    double (*fromKelvin)(double);
};

struct TemperatureScale celsius = {
    celsiusIsScale,
    celsiusToKelvin,
    celsiusFromKelvin,
};

struct TemperatureScale fahrenheit = {
    fahrenheitIsScale,
    fahrenheitToKelvin,
    fahrenheitFromKelvin,
};

struct TemperatureScale kelvin = {
    kelvinIsScale,
    kelvinToKelvin,
    kelvinFromKelvin,
};

struct TemperatureScale rankine = {
    rankineIsScale,
    rankineToKelvin,
    rankineFromKelvin,
};

struct TemperatureScale delisle = {
    delisleIsScale,
    delisleToKelvin,
    delisleFromKelvin,
};

struct TemperatureScale newton = {
    newtonIsScale,
    newtonToKelvin,
    newtonFromKelvin,
};

typedef double (*converter_t)(double);

converter_t getToKelvinFunction(char *temperatureScale) {
    struct TemperatureScale temperatureScales[] = {
        celsius, fahrenheit, kelvin, rankine, delisle, newton
    };
    for (int i = 0; i < sizeof(temperatureScales) / sizeof(temperatureScales[0]); i++) {
        if (temperatureScales[i].isScale(temperatureScale)) {
            return temperatureScales[i].toKelvin;
        }
    }
    fprintf(stderr, "error: Unsupported temperature scale: %s\n", temperatureScale);
    exit(EXIT_FAILURE);
}

converter_t getFromKelvinFunction(char *temperatureScale) {
    struct TemperatureScale temperatureScales[] = {
        celsius, fahrenheit, kelvin, rankine, delisle, newton
    };
    for (int i = 0; i < sizeof(temperatureScales) / sizeof(temperatureScales[0]); i++) {
        if (temperatureScales[i].isScale(temperatureScale)) {
            return temperatureScales[i].fromKelvin;
        }
    }
    fprintf(stderr, "error: Unsupported temperature scale: %s\n", temperatureScale);
    exit(EXIT_FAILURE);
}


void runTests() {
    assert(celsius.isScale("C"));
    assert(celsius.isScale("°C"));
    assert(celsius.isScale("c"));
    assert(celsius.isScale("Celsius"));
    assert(celsius.isScale("celsius"));

    assert(fahrenheit.isScale("F"));
    assert(fahrenheit.isScale("°F"));
    assert(fahrenheit.isScale("f"));
    assert(fahrenheit.isScale("Fahrenheit"));
    assert(fahrenheit.isScale("fahrenheit"));

    assert(kelvin.isScale("K"));
    assert(kelvin.isScale("k"));
    assert(kelvin.isScale("Kelvin"));
    assert(kelvin.isScale("kelvin"));

    assert(fabs(celsius.toKelvin(         0    ) -  273.15 ) < 0.001);
    assert(fabs(celsius.toKelvin(      -273.15 ) -    0    ) < 0.001);
    assert(fabs(fahrenheit.toKelvin(      0    ) -  255.372) < 0.001);
    assert(fabs(fahrenheit.toKelvin(   -459.67 ) -    0    ) < 0.001);

    assert(fabs(celsius.fromKelvin(         0    ) - -273.15 ) < 0.001);
    assert(fabs(celsius.fromKelvin(       273.15 ) -    0    ) < 0.001);
    assert(fabs(fahrenheit.fromKelvin(      0    ) - -459.67 ) < 0.001);
    assert(fabs(fahrenheit.fromKelvin(    255.372) -    0    ) < 0.001);
}

int main(int argc, char *argv[]) {
    runTests();

    if (argc < 3) {
        fprintf(stderr, "%s: error: Not enough arguments.\nUsage: %s INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    converter_t toKelvin = getToKelvinFunction(argv[1]);
    converter_t fromKelvin = getFromKelvinFunction(argv[2]);

    for (int i = 3; i < argc; i++) {
        double inputTemperature = atof(argv[i]);
        double temperature = toKelvin(inputTemperature);
        double outputTemperature = fromKelvin(temperature);

        printf("%f\n", outputTemperature);
    }

    return EXIT_SUCCESS;
}
