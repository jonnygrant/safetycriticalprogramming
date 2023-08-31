# safetycriticalprogramming
Safety Critical Programming

Written after the UK NATS air traffic control system went down due to a corrupted flight path being uploaded. UK suffered flight chaos 28 August 2023

Air traffic controller: system collapsed because it 'didn’t recognise a message'

Martin Rolfe, chief executive of Nats, the UK’s air traffic controller, has apologised for the collapse and said that part of the system collapsed because it “didn’t recognise a message”.

Rolfe said:
"If we receive an unusual piece of data, a piece of data that we don’t recognise, it is critically important that that information, which could be erroneous, is not passed to air traffic controllers."

When resolving data, sanity check pointers are within bounds. Or use a virtual machine with a tight memory range.

A robust CRC on the whole file. Can even have subsection CRCs.
The bounds of every field must be checked. So a geo coordinate double precision number must be within range. Take Latitude and Longitude as an example, Longitude must be within the range -180.0 to +180.0. Latitude must be within the range -90.0 to +90.0. That is Decimal degrees (DD). There is also Degrees, minutes, and seconds (DMS)

An offset must not point to the end of the file, or beyond. An offset to an object or structure must account for the size of that object and compare to the file size to ensure not off the end.

Negative offsets aren't allowed. All size_t. Safer to limit to 32bit. Users can link multiple files if needed.

Choose a suitable max file size, be that 1MB or 10GB



Where operations are transactions, or flight paths etc, the actual changes that are made in memory/data must be recorded in the applied transaction must be recorded. This then allows the transaction to be reversed if needed. Of course should include a unique transaction number, to make an reconciliations later possible.

Making the transaction changes to data in memory in a memory protected virtual machine to prevent any changes being made due to corruption or buffer overflows elsewhere. That virtual machine would detect any changes outside the memory protected buffer.

After making the changes to the buffer, run same sanity checks on it, and the fields to check valid.

Fixed size fields are good. Put a unique repeatable 32 byte signature after, and check for corruption after changes are made.

Limit strings to only A...Z Space and numbers. Don't accept UTF8 or other Unicode.

If it's a real file, can rely upon the OS to check read offsets. Or use a virtual buffer API. In C++ can throw an exception with any invalid data size.


