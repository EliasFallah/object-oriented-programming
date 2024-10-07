import constants

class Vehicle:
    def __init__(self):
        self.vehicle_id = 0
        self.current_city_id = 0
        self.destination_id = 0
        self.capacity_range = 0
        self.remain_range = 0
        self.first_recharge = 0
        self.second_recharge = 0

    def farthest_city(self):
        cumulative_distance = 0
        for i in range(self.current_city_id, self.destination_id + 1):
            if (cumulative_distance + constants.distance_map[i]) > self.remain_range:
                return i - 1
            cumulative_distance += constants.distance_map[i]
        return self.destination_id
