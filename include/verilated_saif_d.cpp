#include <verilated_saif_c.h>
#include <verilated_trace.h>
//=============================================================================
// VerilatedSaifC
// Class representing a SAIF dump file in C standalone (no SystemC)
// simulations. Also derived for use in SystemC simulations.

class ESDLVerilatedSaifD {
    VerilatedSaifC* m_saif_c;  // Trace file being created

public:
    // Construct the dump. Optional argument is ignored
    explicit ESDLVerilatedSaifD(void* filep = nullptr);
    // Destruct, flush, and close the dump
    virtual ~ESDLVerilatedSaifD();

    // METHODS - User called

    // Return if file is open
    bool isOpen() const VL_MT_SAFE;
    // Open a new SAIF file
    // This includes a complete header dump each time it is called,
    // just as if this object was deleted and reconstructed.
    void open(const char* filename) VL_MT_SAFE;

    void rolloverSize(size_t size) VL_MT_SAFE;  // NOP

    // Close dump
    void close() VL_MT_SAFE;
    // Flush dump
    void flush() VL_MT_SAFE;
    // Write one cycle of dump data
    // Call with the current context's time just after eval'ed,
    // e.g. ->dump(contextp->time())
    void dump(uint64_t timeui) VL_MT_SAFE;
    // Write one cycle of dump data - backward compatible and to reduce
    // conversion warnings.  It's better to use a uint64_t time instead.
    void dump(double timestamp);
    void dump(uint32_t timestamp);
    void dump(int timestamp);

    // METHODS - Internal/backward compatible
    // \protectedsection

    // Set time units (s/ms, defaults to ns)
    // Users should not need to call this, as for Verilated models, these
    // propagate from the Verilated default timeunit
    void set_time_unit(const char* unit) VL_MT_SAFE;
    void set_time_unit(const std::string& unit) VL_MT_SAFE;
    // Set time resolution (s/ms, defaults to ns)
    // Users should not need to call this, as for Verilated models, these
    // propagate from the Verilated default timeprecision
    void set_time_resolution(const char* unit) VL_MT_SAFE;
    void set_time_resolution(const std::string& unit) VL_MT_SAFE;
    // Set variables to dump, using $dumpvars format
    // If level = 0, dump everything and hier is then ignored
    void dumpvars(int level, const std::string& hier) VL_MT_SAFE;

    // Internal class access
    VerilatedSaif* spTrace();

    // C++ Class Object Access
    VerilatedSaifC* getTrace();
    VerilatedTraceBaseC* getTraceBase();
};

// Construct the dump. Optional argument is ignored
ESDLVerilatedSaifD::ESDLVerilatedSaifD(void* filep) { m_saif_c = new VerilatedSaifC(filep); }
// Destruct, flush, and close the dump
ESDLVerilatedSaifD::~ESDLVerilatedSaifD() { delete m_saif_c; }

// METHODS - User called

// Return if file is open
bool ESDLVerilatedSaifD::isOpen() const VL_MT_SAFE { return m_saif_c->isOpen(); }
// Open a new SAIF file
// This includes a complete header dump each time it is called,
// just as if this object was deleted and reconstructed.
void ESDLVerilatedSaifD::open(const char* filename) VL_MT_SAFE { m_saif_c->open(filename); }

void ESDLVerilatedSaifD::rolloverSize(size_t size) VL_MT_SAFE {}  // NOP

// Close dump
void ESDLVerilatedSaifD::close() VL_MT_SAFE { m_saif_c->close(); }
// Flush dump
void ESDLVerilatedSaifD::flush() VL_MT_SAFE { m_saif_c->flush(); }
// Write one cycle of dump data
// Call with the current context's time just after eval'ed,
// e.g. ->dump(contextp->time())
void ESDLVerilatedSaifD::dump(uint64_t timeui) VL_MT_SAFE { m_saif_c->dump(timeui); }
// Write one cycle of dump data - backward compatible and to reduce
// conversion warnings.  It's better to use a uint64_t time instead.
void ESDLVerilatedSaifD::dump(double timestamp) { m_saif_c->dump(timestamp); }
void ESDLVerilatedSaifD::dump(uint32_t timestamp) { m_saif_c->dump(timestamp); }
void ESDLVerilatedSaifD::dump(int timestamp) { m_saif_c->dump(timestamp); }

// METHODS - Internal/backward compatible
// \protectedsection

// Set time units (s/ms, defaults to ns)
// Users should not need to call this, as for Verilated models, these
// propagate from the Verilated default timeunit
void ESDLVerilatedSaifD::set_time_unit(const char* unit) VL_MT_SAFE {
    m_saif_c->set_time_unit(unit);
}
void ESDLVerilatedSaifD::set_time_unit(const std::string& unit) VL_MT_SAFE {
    m_saif_c->set_time_unit(unit);
}
// Set time resolution (s/ms, defaults to ns)
// Users should not need to call this, as for Verilated models, these
// propagate from the Verilated default timeprecision
void ESDLVerilatedSaifD::set_time_resolution(const char* unit) VL_MT_SAFE {
    m_saif_c->set_time_resolution(unit);
}
void ESDLVerilatedSaifD::set_time_resolution(const std::string& unit) VL_MT_SAFE {
    m_saif_c->set_time_resolution(unit);
}
// Set variables to dump, using $dumpvars format
// If level = 0, dump everything and hier is then ignored
void ESDLVerilatedSaifD::dumpvars(int level, const std::string& hier) VL_MT_SAFE {
    m_saif_c->dumpvars(level, hier);
}

// Internal class access
VerilatedSaif* ESDLVerilatedSaifD::spTrace() { return m_saif_c->spTrace(); }

// C++ Class Object Access
VerilatedSaifC* ESDLVerilatedSaifD::getTrace() { return m_saif_c; }
VerilatedTraceBaseC* ESDLVerilatedSaifD::getTraceBase() { return m_saif_c; }

ESDLVerilatedSaifD* createSaifD(void* filep = nullptr) { return new ESDLVerilatedSaifD(filep); }
