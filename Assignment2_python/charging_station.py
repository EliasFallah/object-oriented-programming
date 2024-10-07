import constants

class ChargingStation:
    def __init__(self, city_id):
        self.city_id = city_id
        self.city_name = self.name_of_city(city_id)
        self.distance_to_last_city = constants.distance_map[city_id]
        self.distance_to_sydney = self.get_distance_to_sydney(city_id)
        self.number_of_chargers = constants.chargers_map[city_id]
        self.queue_length = 0

    def get_distance_to_sydney(self, city_id):
        cumulative_distance = sum(constants.distance_map[:city_id + 1])
        return cumulative_distance

    def name_of_city(self, city_id):
        return constants.name_map[city_id]

    def calculate_queue_length(self):
        return (self.queue_length * 0.5) / self.number_of_chargers
