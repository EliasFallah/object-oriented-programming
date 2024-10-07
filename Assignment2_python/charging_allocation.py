import constants
from vehicle import Vehicle
from charging_station import ChargingStation

class ChargingAllocation:
    def __init__(self):
        self.vehicles = []
        self.chargers = []
        self.generate_vehicles()
        self.generate_chargers()

    def generate_vehicles(self):
        with open("NewChargingDemands.txt", "r") as charging_demands:
            for line in charging_demands:
                v = Vehicle()
                int_texts = line.strip().split(",")
                v.vehicle_id = int(int_texts[0])
                v.destination_id = int(int_texts[1])
                v.capacity_range = int(int_texts[2])
                v.remain_range = int(int_texts[3])
                self.vehicles.append(v)

    def display_vehicles(self):
        print("Vehicle Information - ")
        print(f"{'Vehicle ID':<15}{'Origin':<10}{'Destination ID':<20}{'Capacity Range':<20}{'Remaining Range':<20}")
        for v in self.vehicles:
            print(f"{v.vehicle_id:<15}{constants.name_map[v.current_city_id]:<10}{constants.name_map[v.destination_id]:<25}{v.capacity_range:<20}{v.remain_range:<20}")
        print("\n")

    def generate_chargers(self):
        for i in range(constants.NUM_CITIES):
            cs = ChargingStation(i)
            self.chargers.append(cs)

    def display_chargers(self):
        print("Charging Station Information - ")
        print(f"{'Location ID':<20}{'Location Name':<25}{'Distance to Sydney':<20}{'No of Chargers':<20}")
        for cs in self.chargers:
            print(f"{cs.city_id:<20}{cs.city_name:<25}{cs.distance_to_sydney:<20}{cs.number_of_chargers:<20}")
        print("\n")

    def allocate_charging(self):
        for v in self.vehicles:
            if v.destination_id > v.farthest_city():
                v.first_recharge = v.farthest_city()
                self.chargers[v.first_recharge].queue_length += 1
                v.current_city_id = v.first_recharge
                v.remain_range = v.capacity_range
                if v.destination_id > v.farthest_city():
                    v.second_recharge = v.farthest_city()
                    self.chargers[v.second_recharge].queue_length += 1
                    v.current_city_id = v.second_recharge
                    v.remain_range = v.capacity_range

    def print_charging(self):
        print("Initial Charging Allocation - ")
        print(f"{'Vehicle ID':<20}{'Destination':<20}{'Capacity Range':<20}{'Remaining Range':<20}{'First Recharge':<20}{'Second Recharge':<20}")
        for v in self.vehicles:
            first_recharge_name = self.chargers[v.first_recharge].city_name if v.first_recharge else "----"
            second_recharge_name = self.chargers[v.second_recharge].city_name if v.second_recharge else "----"
            print(f"{v.vehicle_id:<20}{constants.name_map[v.destination_id]:<20}{v.capacity_range:<20}{v.remain_range:<20}{first_recharge_name:<20}{second_recharge_name:<20}")
        print("\n")
        self.display_queue()

    def display_queue(self):
        print("Queue Length - ")
        print(f"{'Location ID':<20}{'Location Name':<25}{'Distance to Sydney':<20}{'No of Chargers':<20}{'Queue Length':<20}{'Waiting Hours':<20}")
        for cs in self.chargers:
            waiting_hours = cs.calculate_queue_length()
            print(f"{cs.city_id:<20}{cs.city_name:<25}{cs.distance_to_sydney:<20}{cs.number_of_chargers:<20}{cs.queue_length:<20}{waiting_hours:.2f} hours")
