enum int_type {
    INT,
    UINT,
    LONG,
    ULONG,
    LONGLONG,
    ULONGLONG
};

struct integer {
    unsigned long long value;
    enum int_type type;
};
