*Irrelevant details are truncated using ellipses*

# fract'ol

## Computer Graphics Fractals

*Summary: This project involves creating graphically beautiful fractals.*

*Version: 5.0*

---

## Contents

- [I – Foreword](#chapter-i--foreword)
- [II – Introduction](#chapter-ii--introduction)
- [III – Objectives](#chapter-iii--objectives)
- [IV – Common Instructions](#chapter-iv--common-instructions)
- [V – AI Instructions](#chapter-v--ai-instructions)
- [VI – Mandatory part](#chapter-vi--mandatory-part)
  - [VI.1 – Rendering](#vi1-rendering)
  - [VI.2 – Graphic management](#vi2-graphic-management)
- [VII – Readme Requirements](#chapter-vii--readme-requirements)
- [VIII – Bonus part](#chapter-viii--bonus-part)
- [IX – Submission and peer-evaluation](#chapter-ix--submission-and-peer-evaluation)

---

## Chapter I – Foreword

[...]

---

## Chapter II – Introduction

The term *fractal* was first used by mathematician Benoit Mandelbrot in 1974. He based it on the Latin word *fractus* which means "broken" or "fractured".

A fractal is an abstract mathematical object, such as a curve or a surface, whose pattern remains consistent at every scale.

Various natural phenomena, such as the Romanesco cabbage, exhibit fractal features.

Now, it's your turn to generate some magnificent fractals!

---

## Chapter III – Objectives

It's time for you to create a basic computer graphics project!

You will use the school's graphical library, the `MiniLibX`. This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

This will be an opportunity for you to become familiar with the `MiniLibX` library, discover or use the mathematical concept of **complex numbers**, explore computer graphics **optimization**, and practice **event handling**.

---

## Chapter IV – Common Instructions

- Your project must be written in C.

- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check, and you will receive a 0 if there is a norm error.

- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior. If this occurs, your project will be considered non-functional and will receive a 0 during the evaluation.

- All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated.

- If the subject requires it, you must submit a `Makefile` that compiles your source files to the required output with the flags `-Wall`, `-Wextra`, and `-Werror`, using `cc`. Additionally, your `Makefile` must not perform unnecessary relinking.

- Your `Makefile` must contain at least the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`.

- To submit bonuses for your project, you must include a `bonus` rule in your `Makefile`, which will add all the various headers, libraries, or functions that are not allowed in the main part of the project. Bonuses must be placed in `_bonus.{c/h}` files, unless the subject specifies otherwise. The evaluation of mandatory and bonus parts is conducted separately.

- If your project allows you to use your `libft`, you must copy its sources and its associated `Makefile` into a `libft` folder. Your project's `Makefile` must compile the library by using its `Makefile`, then compile the project.

- We encourage you to create test programs for your project, even though this work **does not need to be submitted and will not be graded**. It will give you an opportunity to easily test your work and your peers' work. You will find these tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.

- Submit your work to the assigned Git repository. Only the work in the Git repository will be graded. If Deepthought is assigned to grade your work, it will occur after your peer-evaluations. If an error happens in any section of your work during Deepthought's grading, the evaluation will stop.

---

## Chapter V – AI Instructions

[...]

---

## Chapter VI – Mandatory part

| Field | Value |
|---|---|
| **Program Name** | `fractol` |
| **Files to Submit** | `Makefile`, `*.h`, `*.c` |
| **Makefile** | `NAME`, `all`, `clean`, `fclean`, `re` |
| **Arguments** | The type of fractal to display and any other option available |
| **External Function** | `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`. All functions of the math library (`-lm` compiler option, `man 3 math`). All functions of the MiniLibX library. `gettimeofday()`. `ft_printf` or any equivalent YOU coded. |
| **Libft authorized** | Yes |
| **Description** | This project is about creating a small fractal exploration program. First, you need to understand what a fractal is. |

Your project must comply with the following rules:

- You **must** use the `MiniLibX` library. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a `Makefile` which will compile your source files. It must not relink.
- Global variables are forbidden.

### VI.1 Rendering

- Your program must offer the **Julia** set and the **Mandelbrot** set.
- The mouse wheel allows zooming in and out almost infinitely (within the computer's limits). This is the very principle of fractals.
- You must be able to create different Julia sets by passing different parameters to the program.
- A parameter is passed on the command line to define what type of fractal will be displayed in a window.
  - You can handle more parameters to use them as rendering options.
  - If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
- You must use at least a few **colors** to reveal the depth of each fractal. Experimenting with psychedelic effects is encouraged.

### VI.2 Graphic management

- Your program has to display the image in a window.
- Window management must remain smooth (e.g., switching to another window, minimizing, etc.).
- Pressing `ESC` must close the window and quit the program in a clean way.
- Clicking on the cross on the window's frame must close the window and quit the program in a clean way.
- The use of the **images** of the MiniLibX library is mandatory.

---

## Chapter VII – Readme Requirements

A `README.md` file must be provided at the root of your Git repository. Its purpose is to allow anyone unfamiliar with the project (peers, staff, recruiters, etc.) to quickly understand what the project is about, how to run it, and where to find more information on the topic.

The `README.md` must include at least:

- The very first line must be italicized and read: *This project has been created as part of the 42 curriculum by \<login1\>[, \<login2\>[, \<login3\>[...]]]].*
- A "**Description**" section that clearly presents the project, including its goal and a brief overview.
- An "**Instructions**" section containing any relevant information about compilation, installation, and/or execution.
- A "**Resources**" section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.

> **Additional sections may be required depending on the project** (e.g., usage examples, feature list, technical choices, etc.).

Any required additions will be explicitly listed below.

> English is recommended; alternatively, you may use the main language of your campus.

---

## Chapter VIII – Bonus part

Typically, you would be encouraged to develop your own original additional features; however, more interesting graphic projects await you in the future. Don't spend too much time on this assignment!

You will get some extra points with the following features:

- One more different fractal (more than a hundred different types of fractals are referenced online).
- The zoom follows the actual mouse position.
- In addition to zooming, allow moving the view using the arrow keys.
- Make the color range shift.

> **The bonus part will only be assessed if the mandatory part is PERFECT.** Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

---

## Chapter IX – Submission and peer-evaluation

Submit your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your files to ensure they are correct.

As these assignments are not verified by a program, feel free to organize your files as you wish, provided you submit the mandatory files and comply with the requirements.

During the evaluation, a brief **modification of the project** may occasionally be requested. This could involve a minor behavior change, a few lines of code to write or rewrite, or an easy-to-add feature.

While this step may **not be applicable to every project**, you must be prepared for it if it is mentioned in the evaluation guidelines.

This step is meant to verify your actual understanding of a specific part of the project. The modification can be performed in any development environment you choose (e.g., your usual setup), and it should be feasible within a few minutes — unless a specific timeframe is defined as part of the evaluation.

You can, for example, be asked to make a small update to a function or script, modify a display, or adjust a data structure to store new information, etc.

The details (scope, target, etc.) will be specified in the **evaluation guidelines** and may vary from one evaluation to another for the same project.