#!/usr/bin/env python

import glob
import os
import sys
import time

try:
    sys.path.append(glob.glob('../carla/dist/carla-*%d.%d-%s.egg' % (
        sys.version_info.major,
        sys.version_info.minor,
        'win-amd64' if os.name == 'nt' else 'linux-x86_64'))[0])
except IndexError:
    pass

import carla

def main():
    actor_list = []

    try:
        # Connect to the Carla server
        client = carla.Client('localhost', 2000)
        client.set_timeout(30.0)

        # Load the Carla world
        world = client.get_world()

        # Get the blueprint of the vehicle we want to spawn
        blueprint_library = world.get_blueprint_library()
        vehicle_blueprint = blueprint_library.find('vehicle.audi.a2')

        # Set the spawn location for the vehicle
        spawn_point = carla.Transform(carla.Location(x=2.0, y=0.0, z=0.5), carla.Rotation())

        # Spawn the vehicle
        vehicle = world.spawn_actor(vehicle_blueprint, spawn_point)
        actor_list.append(vehicle)

        # Enable autopilot for the vehicle
        vehicle.set_autopilot(True)

        # Let the simulation run for 10 seconds
        time.sleep(10)

    finally:
        print('Destroying actors...')
        for actor in actor_list:
            actor.destroy()

if __name__ == '__main__':
    main()
