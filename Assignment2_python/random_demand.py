# DECLARATION
# I hold a copy of this assignment that I can produce if the original is lost or damaged.
# I hereby certify that no part of this assignment has been copied from any other student’s work or
# from any other source except where due acknowledgement is made in the assignment. No part
# of this assignment has been written/produced for me by another person except where such
# collaboration has been authorised by the subject lecturer concerned.

from demand_generator import DemandGenerator
from charging_allocation import ChargingAllocation

def main():
    demand_gen = DemandGenerator() 
    charging_alloc = ChargingAllocation() 
    charging_alloc.display_vehicles() 
    charging_alloc.display_chargers()  
    charging_alloc.allocate_charging()  
    charging_alloc.print_charging()  

if __name__ == "__main__":
    main()
