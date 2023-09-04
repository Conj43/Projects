import requests 

api_key = '0a4a84d8d6ac73ba1ce18c937678560b'

location = input('Enter the name of the city you would like to view (i.e. New York,US): ')

url = f'https://api.openweathermap.org/data/2.5/weather?q={location}&appid={api_key}'

response = requests.get(url)

if response.status_code == 200:
    data = response.json()

    weather_description = data['weather'][0]['description']
    temperature = data['main']['temp'] - 273.15

    print(f"Weather in {location}: {weather_description.capitalize()}")
    print(f"Temperature: {temperature:.2f} C")
else:
    print(f"Error: Unable to retreive data for {location}")
