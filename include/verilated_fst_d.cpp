#include "verilated_trace.h"
#include <verilated_fst_c.h>

//=============================================================================
// ESDLVerilatedFstD
/// VerilatedFstC class wrapper for interfacing with Dlang

class ESDLVerilatedFstD {
public:
    VerilatedFstC* m_fst_c;

    /// Construct the dump. Optional argument is ignored.
    explicit ESDLVerilatedFstD(void* filep = nullptr);
    /// Destruct, flush, and close the dump
    virtual ~ESDLVerilatedFstD();

    // METHODS - User called

    /// Return if file is open
    bool isOpen() const VL_MT_SAFE;
    /// Open a new FST file
    void open(const char* filename) VL_MT_SAFE;
    /// Close dump
    void close() VL_MT_SAFE;
    /// Flush dump
    void flush() VL_MT_SAFE;
    /// Write one cycle of dump data
    /// Call with the current context's time just after eval'ed,
    /// e.g. ->dump(contextp->time())
    void dump(uint64_t timeui);
    /// Write one cycle of dump data - backward compatible and to reduce
    /// conversion warnings.  It's better to use a uint64_t time instead.
    void dump(double timestamp);
    void dump(uint32_t timestamp);
    void dump(int timestamp);

    // METHODS - Internal/backward compatible
    // \protectedsection

    // Set time units (s/ms, defaults to ns)
    // Users should not need to call this, as for Verilated models, these
    // propagate from the Verilated default timeunit
    void set_time_unit(const char* unitp) VL_MT_SAFE;
    void set_time_unit(const std::string& unit) VL_MT_SAFE;
    // Set time resolution (s/ms, defaults to ns)
    // Users should not need to call this, as for Verilated models, these
    // propagate from the Verilated default timeprecision
    void set_time_resolution(const char* unitp) VL_MT_SAFE;
    void set_time_resolution(const std::string& unit) VL_MT_SAFE;
    // Set variables to dump, using $dumpvars format
    // If level = 0, dump everything and hier is then ignored
    void dumpvars(int level, const std::string& hier) VL_MT_SAFE;

    // Internal class access
    VerilatedFst* spTrace();

    // C++ Class Object Access
    VerilatedFstC* getTrace();
    VerilatedTraceBaseC* getTraceBase();
};

/// Construct the dump. Optional argument is ignored.
ESDLVerilatedFstD::ESDLVerilatedFstD(void* filep) { m_fst_c = new VerilatedFstC(filep); }
/// Destruct, flush, and close the dump
ESDLVerilatedFstD::~ESDLVerilatedFstD() { delete m_fst_c; }

// METHODS - User called

/// Return if file is open
bool ESDLVerilatedFstD::isOpen() const VL_MT_SAFE { return m_fst_c->isOpen(); }
/// Open a new FST file
void ESDLVerilatedFstD::open(const char* filename) VL_MT_SAFE { m_fst_c->open(filename); };
/// Close dump
void ESDLVerilatedFstD::close() VL_MT_SAFE { m_fst_c->close(); }
/// Flush dump
void ESDLVerilatedFstD::flush() VL_MT_SAFE { m_fst_c->flush(); }
/// Write one cycle of dump data
/// Call with the current context's time just after eval'ed,
/// e.g. ->dump(contextp->time())
void ESDLVerilatedFstD::dump(uint64_t timeui) { m_fst_c->dump(timeui); }
/// Write one cycle of dump data - backward compatible and to reduce
/// conversion warnings.  It's better to use a uint64_t time instead.
void ESDLVerilatedFstD::dump(double timestamp) { m_fst_c->dump(timestamp); }
void ESDLVerilatedFstD::dump(uint32_t timestamp) { m_fst_c->dump(timestamp); }
void ESDLVerilatedFstD::dump(int timestamp) { m_fst_c->dump(timestamp); }

// METHODS - Internal/backward compatible
// \protectedsection

// Set time units (s/ms, defaults to ns)
// Users should not need to call this, as for Verilated models, these
// propagate from the Verilated default timeunit
void ESDLVerilatedFstD::set_time_unit(const char* unitp) VL_MT_SAFE {
    m_fst_c->set_time_unit(unitp);
}
void ESDLVerilatedFstD::set_time_unit(const std::string& unit) VL_MT_SAFE {
    m_fst_c->set_time_unit(unit);
}
// Set time resolution (s/ms, defaults to ns)
// Users should not need to call this, as for Verilated models, these
// propagate from the Verilated default timeprecision
void ESDLVerilatedFstD::set_time_resolution(const char* unitp) VL_MT_SAFE {
    m_fst_c->set_time_resolution(unitp);
}
void ESDLVerilatedFstD::set_time_resolution(const std::string& unit) VL_MT_SAFE {
    m_fst_c->set_time_resolution(unit);
}
// Set variables to dump, using $dumpvars format
// If level = 0, dump everything and hier is then ignored
void ESDLVerilatedFstD::dumpvars(int level, const std::string& hier) VL_MT_SAFE {
    m_fst_c->dumpvars(level, hier);
}

// Internal class access
VerilatedFst* ESDLVerilatedFstD::spTrace() { return m_fst_c->spTrace(); }

// C++ Class Object Access
VerilatedFstC* ESDLVerilatedFstD::getTrace() { return m_fst_c; }
VerilatedTraceBaseC* ESDLVerilatedFstD::getTraceBase() { return m_fst_c; }

ESDLVerilatedFstD* createFstD(void* filep = nullptr) { return new ESDLVerilatedFstD(filep); }
