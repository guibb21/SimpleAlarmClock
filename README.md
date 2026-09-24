# SimpleAlarmClock

A command-line alarm clock written in C. (made in about 1 hour)

## How it works

The user sets an alarm time in `HH:MM` format. The program calculates how many seconds remain until that time and uses `sleep()` to wait. When the alarm fires, the terminal clears and displays a math problem — the alarm only disarms once the correct answer is entered.

## Concepts used

- Time manipulation with `time()`, `localtime()`, `mktime()` and `ctime()`
- Input validation using `fgets` + `sscanf`
- Automatic next-day scheduling if the alarm time has already passed today

## Usage

**Compile:**
```
gcc SimpleAlarmClock.c -o alarm
```

**Run:**
```
./alarm
```

Enter the alarm time when prompted (e.g. `7:30`). The program will wait until that time and wake you up with a math problem.

## Environment

Developed on Linux. Requires GCC.
