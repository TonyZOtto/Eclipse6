TEMPLATE = subdirs

SUBDIRS = \
    eirBase6        \
    eirCore6        \
    If6Console      \

If6Console.subdir       = ./console/If6Console
eirBase6.subdir         = ./libs/eirBase6
eirCore6.subdir         = ./libs/eirCore6

eirCore6.depends        = eirBase6
If6Console.depends      = eirBase6 eirCore6
