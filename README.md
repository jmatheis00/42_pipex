# pipex_42
>The Pipex project deepens understanding of Unix concepts such as Redirections and Pipes,
>providing an introduction to more advanced Unix tasks.
>This project involves creating a program that replicates the functionality of shell commands using pipes and data redirection,
>like `< file1 cmd1 | cmd2 > file2`. 
>The mandatory part focuses on handling two commands,
>while the bonus part allows you to work with multiple commands and introduces "here_doc" functionality.
>Throughout the project, there is a strong focus on error handling, memory management and of course proper handling of pipes,
>providing valuable insights into Unix data flow.

### Usage
1. clone this repository and `cd` into it:

```zsh
git clone https://github.com/jmatheis00/42_pipex.git && cd 42_pipex
```

---

**2.1 MANDATORY PART**

2.1.1 Compile the project using make:

```zsh
make
```

2.1.2 Run the project with the following command:

```zsh
./pipex file1 cmd1 cmd2 file2
```
> behaves like this shell command: `< file1 cmd1 | cmd2 > file2`
 
---

**2.2 BONUS PART**

2.2.1 Compile the project using make bonus:

```zsh
make bonus
```

2.2.2 Run the project with one of the following commands:

Multiple commands:
```zsh
./pipex file1 cmd1 cmd2 ... cmdn file2
```
> behaves like this shell command: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

Here_doc:
```zsh
./pipex here_doc LIMITER cmd cmd1 file
```
> behaves like this shell commmand: ` cmd << LIMITER | cmd1 >> file`
