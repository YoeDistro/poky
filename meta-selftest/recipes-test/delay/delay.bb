SUMMARY = "Recipe with a fixed delay task"
DESCRIPTION = "Contains a delay task to be used to for testing."
LICENSE = "MIT"

INHIBIT_DEFAULT_DEPS = "1"
EXCLUDE_FROM_WORLD = "1"

# This recipe is used by the disk space monitor tests so we need a task that executes
# a few seconds after first task to give the monitor time to trigger.

do_first_delay_task () {
	sleep 3
}
do_delay() {
	sleep 3
}
do_delay[nostamp] = "1"
addtask first_delay_task
addtask delay after do_first_delay_task
