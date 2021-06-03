## Dependency tree

`package_d` -> `package_b`

`package_d` -> `package_c`

`package_c` -> `package_a`

## Reproduction steps

To reproduce a dependency issue, build an underlay workspace with a merge install space

        cd underlay
        colcon build --merge-install

Source the underlay and build the overlay


        source install/setup.bash
        cd ../overlay
        colcon build

Expect a compiler error due to an undeclared function `package_a_foo_new`.

## Explanation

`package_a` exists in both the underlay and overlay, with a modified version in the overlay.
`package_c` depends on the modified version of `package_a`; a sibling in the overlay.
`package_d` depends on `package_c` **and** `package_b` (a package in the underlay).

`package_d` happens to order the include directories such that `package_b` appears before `package_c`.
Since the underlay is a merge install, the include directoy for `package_b` is the same as for `package_a`.
Unfortunately, this means that `package_b` will include headers from `package_a` in the underlay instead of the overlay.
