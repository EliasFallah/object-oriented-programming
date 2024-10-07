import random
import constants

class DemandGenerator:
    def __init__(self):
        random.seed()  # Initialize random number generator
        self.file_name = "NewChargingDemands.txt"
        self.num_demands = random.randint(350, 400)  # Generate a random number of demands between 350 and 400

        with open(self.file_name, "w") as charging_demands:
            for i in range(200, self.num_demands):
                self.new_demand(i)
                new_demands = f"{self.vehicle_id},{self.destination_id},{self.capacity_range},{self.remain_range}"
                charging_demands.write(new_demands + "\n")

        print("New Charging Demands Generated\n")

    def new_demand(self, num):
        self.vehicle_id = num
        self.destination_id = random.randint(1, constants.NUM_CITIES - 1)  # Random destination between 1 and NUM_CITIES-1
        self.capacity_range = random.randint(350, 550)  # Random capacity between 350 and 550
        self.remain_range = random.randint(constants.MIN_REMAIN_RANGE, self.capacity_range)  # Remain range
