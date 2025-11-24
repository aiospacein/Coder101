from reportlab.lib.pagesizes import letter
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer
from reportlab.lib.styles import getSampleStyleSheet

pdf_path = "/mnt/data/C_Keywords_Full_Reference.pdf"
doc = SimpleDocTemplate(pdf_path, pagesize=letter)
styles = getSampleStyleSheet()
content = []

def add(text):
    content.append(Paragraph(text, styles["Normal"]))
    content.append(Spacer(1,10))

add("<b>C Language Keywords & Compiler Extensions – Complete Reference</b>")
add("<b>Section A – ISO C Language Keywords</b>")
add("C90 (32 keywords): auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int, long, register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while")
add("C99 (added 5): _Bool, _Complex, _Imaginary, inline, restrict")
add("C11 (added 7): _Alignas, _Alignof, _Atomic, _Generic, _Noreturn, _Static_assert, _Thread_local")
add("C23 (added 5): bool, nullptr, true, false, typeof")

add("<b>Section B – Preprocessor Directives</b>")
add("#define, #undef, #include, #error, #warning, #line, #if, #ifdef, #ifndef, #elif, #else, #endif, #pragma")

add("<b>Section C – GCC / Clang Extensions</b>")
add("include_next, assert, unassert, warning (pre‑C23), __attribute__, typeof (standard in C23), asm, __asm__, __inline__, __restrict__, __volatile__, __auto_type")

add("<b>Section D – MSVC Extensions</b>")
add("__declspec, __stdcall, __fastcall, __cdecl, __int8, __int16, __int32, __int64, __alignof, __inline, __noop, __pragma")

add("<b>Why include_next is not in C keyword list</b>")
add("Because include_next is NOT part of ISO C. It is a GNU C preprocessor extension and only meaningful when multiple include paths contain headers of the same name.")

doc.build(content)
pdf_path
