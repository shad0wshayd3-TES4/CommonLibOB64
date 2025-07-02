namespace RE
{
    class TESForm;

    class LEVELED_OBJECT
    {
    public:
        uint16_t level;	// 00
        TESForm* form;	// 08
        uint16_t count;	// 10
    };
    static_assert(offsetof(LEVELED_OBJECT, form) == 0x08);
}
