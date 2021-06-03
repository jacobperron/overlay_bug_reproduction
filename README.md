
To reproduce a dependency issue, build an underlay workspace with a merge install space

        cd underlay
        colcon build --merge-install

Source the underlay and build the overlay


        source install/setup.bash
        cd ../overlay
        colcon build


