*This project has been created as part of the 42 curriculum by jkim2.*

# fract'ol

## Description

`fract'ol` is a small fractal exploration program built with MiniLibX.
It renders the Mandelbrot set and the Julia set, supports interactive zoom,
and allows different Julia shapes through command-line parameters.

The bonus build adds extra fractals and more interactive controls such as
view movement, cursor-following zoom, color-range shifting, and runtime
fractal switching.

## Instructions

### Build

```sh
make
```

Build the bonus version:

```sh
make bonus
```

Remove object files:

```sh
make clean
```

Remove object files and the executable:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

### Run

Mandatory examples:

```sh
./fractol mandelbrot
./fractol julia
./fractol julia 0.285 0.01
./fractol mandelbrot 0066FF
./fractol julia -0.766667 -0.090000 CC6600
```

Bonus examples:

```sh
./fractol burning_ship
./fractol tricorn
./fractol mandelbox
```

### Controls

Mandatory:

- `Mouse wheel`: zoom in and out
- `+` / `-`: zoom in and out
- `ESC`: quit
- Window close button: quit

Bonus:

- `WASD` or arrow keys: move the view
- `Space`: cycle color schemes
- Left click on Julia: change the Julia constant
- `1` `2` `3` `4` `5`: switch fractals

## Usage Notes

- Available mandatory fractals: `mandelbrot`, `julia`
- Julia accepts two optional parameters in the range `[-2.0, 2.0]`
- An optional hexadecimal color may be provided as `RRGGBB`
- Short aliases such as `M`, `J`, `1`, and `2` are also accepted

## Resources

- MiniLibX documentation: the MiniLibX sources included in this repository
- Mandelbrot and Julia overview: https://en.wikipedia.org/wiki/Mandelbrot_set
- Complex numbers refresher: https://en.wikipedia.org/wiki/Complex_number
- Fractal background and references: https://mathworld.wolfram.com/topics/Fractals.html

### AI Usage

AI was used as an assistant for:

- reviewing code structure and argument handling
- checking compliance against the project subject
- improving documentation wording

All final code choices, project structure, build integration, and validation
were reviewed and applied manually in the repository.
