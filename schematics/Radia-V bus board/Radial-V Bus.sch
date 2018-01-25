<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.4.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="con-molex">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="7395-02">
<description>&lt;b&gt;MOLEX 2.54mm KK RA CONNECTOR&lt;/b&gt;
&lt;br&gt;Fixed Orientation</description>
<wire x1="2.54" y1="-5.08" x2="2.54" y2="-1.905" width="0.254" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="1.905" y2="-1.905" width="0.254" layer="21"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-2.54" width="0.254" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="0.635" y2="-2.54" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="0.635" y2="-1.905" width="0.254" layer="21"/>
<wire x1="0.635" y1="-1.905" x2="-0.635" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-1.905" x2="-0.635" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="-1.905" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-1.905" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-1.905" x2="-2.54" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-5.08" x2="-1.651" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-1.651" y1="-5.08" x2="1.27" y2="-5.08" width="0.254" layer="21"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.254" layer="21"/>
<wire x1="1.27" y1="-5.08" x2="1.27" y2="-13.081" width="0.254" layer="21"/>
<wire x1="1.27" y1="-13.081" x2="1.016" y2="-13.589" width="0.254" layer="21"/>
<wire x1="1.016" y1="-13.589" x2="-0.0508" y2="-13.589" width="0.254" layer="21"/>
<wire x1="-1.27" y1="-5.08" x2="-1.27" y2="-13.081" width="0.254" layer="21"/>
<wire x1="-1.27" y1="-13.081" x2="-1.016" y2="-13.589" width="0.254" layer="21"/>
<wire x1="-1.016" y1="-13.589" x2="-0.0508" y2="-13.589" width="0.254" layer="21"/>
<wire x1="-0.0508" y1="-13.589" x2="0.0508" y2="-13.589" width="0.254" layer="21"/>
<wire x1="1.27" y1="-5.08" x2="0.889" y2="-5.08" width="0.254" layer="51"/>
<wire x1="-1.651" y1="-5.08" x2="-1.651" y2="-11.303" width="0.254" layer="21"/>
<wire x1="-1.651" y1="-11.303" x2="-1.3208" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="1.651" y1="-5.08" x2="1.651" y2="-11.303" width="0.254" layer="21"/>
<wire x1="1.651" y1="-11.303" x2="1.3208" y2="-11.6586" width="0.254" layer="21"/>
<pad name="1" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="2.6401" y="2.9479" size="1.016" layer="25" ratio="10" rot="R180">&gt;NAME</text>
<text x="0.7859" y="-3.4021" size="1.27" layer="21" ratio="14" rot="R270">1</text>
<text x="-1.7033" y="-3.2751" size="1.27" layer="21" ratio="14" rot="R270">2</text>
<text x="3.4021" y="-2.4399" size="0.8128" layer="27" ratio="10" rot="R270">&gt;VALUE</text>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-2.5146" x2="1.524" y2="-0.2794" layer="51"/>
<rectangle x1="-1.524" y1="-2.5146" x2="-1.016" y2="-0.2794" layer="51"/>
</package>
<package name="6410-02">
<description>&lt;b&gt;MOLEX 2.54mm KK  CONNECTOR&lt;/b&gt;</description>
<wire x1="-1.27" y1="2.54" x2="-1.27" y2="2.921" width="0.127" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="2.921" width="0.254" layer="21"/>
<wire x1="-2.54" y1="2.921" x2="-1.27" y2="2.921" width="0.254" layer="21"/>
<wire x1="-1.016" y1="2.921" x2="-1.27" y2="2.921" width="0.127" layer="21"/>
<wire x1="-1.27" y1="2.921" x2="0" y2="2.921" width="0.254" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="2.921" width="0.254" layer="21"/>
<wire x1="2.54" y1="2.921" x2="0" y2="2.921" width="0.127" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-2.921" x2="0" y2="-2.921" width="0.254" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-2.921" width="0.254" layer="21"/>
<wire x1="2.54" y1="-2.921" x2="1.905" y2="-2.921" width="0.127" layer="21"/>
<wire x1="1.905" y1="-2.921" x2="0.635" y2="-2.921" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.921" x2="0" y2="-2.921" width="0.127" layer="21"/>
<wire x1="-2.286" y1="-2.921" x2="-1.905" y2="-2.921" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-2.921" x2="-1.905" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.921" x2="-1.905" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.286" x2="-0.635" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-2.286" x2="-0.635" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-2.921" x2="0.635" y2="-2.921" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.921" x2="0.635" y2="-2.286" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.286" x2="1.905" y2="-2.286" width="0.254" layer="21"/>
<wire x1="1.905" y1="-2.286" x2="1.905" y2="-2.921" width="0.254" layer="21"/>
<wire x1="1.905" y1="-2.921" x2="2.54" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.27" y2="2.921" width="0.254" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.016" y2="1.905" width="0.254" layer="21"/>
<wire x1="-1.016" y1="1.905" x2="1.016" y2="1.905" width="0.254" layer="21"/>
<wire x1="1.016" y1="1.905" x2="1.27" y2="1.905" width="0.254" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.27" y2="2.921" width="0.254" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.016" y2="1.397" width="0.254" layer="21"/>
<wire x1="-1.016" y1="2.921" x2="-1.016" y2="1.905" width="0.254" layer="21"/>
<wire x1="-1.016" y1="1.397" x2="1.016" y2="1.397" width="0.254" layer="21"/>
<wire x1="1.016" y1="1.397" x2="1.27" y2="1.905" width="0.254" layer="21"/>
<wire x1="1.016" y1="2.921" x2="1.016" y2="1.905" width="0.254" layer="21"/>
<pad name="2" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="1" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-2.5131" y="3.2751" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="3.2751" y="-0.6111" size="1.27" layer="21" ratio="14">1</text>
<text x="-3.7099" y="-0.6873" size="1.27" layer="21" ratio="14">2</text>
<text x="-2.5131" y="-4.5989" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="MV">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="22-?-02" prefix="J">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 2.54 mm (.1 inch) pitch header</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="05-7028" package="7395-02">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="9731601" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="27-2021" package="6410-02">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lstb">
<description>&lt;b&gt;Pin Headers&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
MA = male&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="MA18-2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-22.225" y1="2.54" x2="-20.955" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-20.955" y1="2.54" x2="-20.32" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="1.905" x2="-19.685" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="2.54" x2="-18.415" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="2.54" x2="-17.78" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-22.225" y1="2.54" x2="-22.86" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="1.905" x2="-17.145" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="2.54" x2="-15.875" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="2.54" x2="-15.24" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="2.54" x2="-13.335" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-13.335" y1="2.54" x2="-12.7" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="1.905" x2="-12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="2.54" x2="-10.795" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="2.54" x2="-10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="2.54" x2="-15.24" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.905" x2="-9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="2.54" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="-1.905" x2="-20.955" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="-1.905" x2="-18.415" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="-2.54" x2="-19.685" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="-2.54" x2="-20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-22.86" y1="1.905" x2="-22.86" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-22.86" y1="-1.905" x2="-22.225" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-20.955" y1="-2.54" x2="-22.225" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-15.875" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="-2.54" x2="-17.145" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="-2.54" x2="-17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="-2.54" x2="-12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="-2.54" x2="-12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-13.335" y1="-2.54" x2="-14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="2.54" x2="7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="2.54" x2="10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-2.54" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.54" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.065" y1="2.54" x2="12.7" y2="1.905" width="0.1524" layer="21"/>
<wire x1="10.795" y1="2.54" x2="12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.795" y2="2.54" width="0.1524" layer="21"/>
<wire x1="10.795" y1="-2.54" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.065" y1="-2.54" x2="10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="13.335" y1="2.54" x2="14.605" y2="2.54" width="0.1524" layer="21"/>
<wire x1="14.605" y1="2.54" x2="15.24" y2="1.905" width="0.1524" layer="21"/>
<wire x1="15.24" y1="1.905" x2="15.875" y2="2.54" width="0.1524" layer="21"/>
<wire x1="15.875" y1="2.54" x2="17.145" y2="2.54" width="0.1524" layer="21"/>
<wire x1="17.145" y1="2.54" x2="17.78" y2="1.905" width="0.1524" layer="21"/>
<wire x1="13.335" y1="2.54" x2="12.7" y2="1.905" width="0.1524" layer="21"/>
<wire x1="17.78" y1="1.905" x2="18.415" y2="2.54" width="0.1524" layer="21"/>
<wire x1="18.415" y1="2.54" x2="19.685" y2="2.54" width="0.1524" layer="21"/>
<wire x1="19.685" y1="2.54" x2="20.32" y2="1.905" width="0.1524" layer="21"/>
<wire x1="20.32" y1="1.905" x2="20.955" y2="2.54" width="0.1524" layer="21"/>
<wire x1="20.955" y1="2.54" x2="22.225" y2="2.54" width="0.1524" layer="21"/>
<wire x1="15.24" y1="-1.905" x2="14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="17.78" y1="-1.905" x2="17.145" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="17.145" y1="-2.54" x2="15.875" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="15.875" y1="-2.54" x2="15.24" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="14.605" y1="-2.54" x2="13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="22.225" y1="-2.54" x2="20.955" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="20.955" y1="-2.54" x2="20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-1.905" x2="19.685" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="19.685" y1="-2.54" x2="18.415" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="18.415" y1="-2.54" x2="17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="22.86" y1="1.905" x2="22.86" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="22.225" y1="2.54" x2="22.86" y2="1.905" width="0.1524" layer="21"/>
<wire x1="22.86" y1="-1.905" x2="22.225" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-21.59" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-19.05" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-16.51" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-13.97" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="-11.43" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="-8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-21.59" y="1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-19.05" y="1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-16.51" y="1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-13.97" y="1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="-11.43" y="1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="-8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="-6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="-6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="-3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="17" x="-1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="19" x="1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="21" x="3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="23" x="6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="25" x="8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="-3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="18" x="-1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="20" x="1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="22" x="3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="24" x="6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="26" x="8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="27" x="11.43" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="28" x="11.43" y="1.27" drill="1.016" shape="octagon"/>
<pad name="29" x="13.97" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="31" x="16.51" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="33" x="19.05" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="30" x="13.97" y="1.27" drill="1.016" shape="octagon"/>
<pad name="32" x="16.51" y="1.27" drill="1.016" shape="octagon"/>
<pad name="34" x="19.05" y="1.27" drill="1.016" shape="octagon"/>
<pad name="35" x="21.59" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="36" x="21.59" y="1.27" drill="1.016" shape="octagon"/>
<text x="-22.098" y="-4.191" size="1.27" layer="21" ratio="10">1</text>
<text x="-22.86" y="2.921" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="7.62" y="-4.191" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="20.32" y="2.921" size="1.27" layer="21" ratio="10">36</text>
<rectangle x1="-19.304" y1="-1.524" x2="-18.796" y2="-1.016" layer="51"/>
<rectangle x1="-21.844" y1="-1.524" x2="-21.336" y2="-1.016" layer="51"/>
<rectangle x1="-16.764" y1="-1.524" x2="-16.256" y2="-1.016" layer="51"/>
<rectangle x1="-11.684" y1="-1.524" x2="-11.176" y2="-1.016" layer="51"/>
<rectangle x1="-14.224" y1="-1.524" x2="-13.716" y2="-1.016" layer="51"/>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-21.844" y1="1.016" x2="-21.336" y2="1.524" layer="51"/>
<rectangle x1="-19.304" y1="1.016" x2="-18.796" y2="1.524" layer="51"/>
<rectangle x1="-16.764" y1="1.016" x2="-16.256" y2="1.524" layer="51"/>
<rectangle x1="-14.224" y1="1.016" x2="-13.716" y2="1.524" layer="51"/>
<rectangle x1="-11.684" y1="1.016" x2="-11.176" y2="1.524" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="11.176" y1="1.016" x2="11.684" y2="1.524" layer="51"/>
<rectangle x1="11.176" y1="-1.524" x2="11.684" y2="-1.016" layer="51"/>
<rectangle x1="16.256" y1="-1.524" x2="16.764" y2="-1.016" layer="51"/>
<rectangle x1="13.716" y1="-1.524" x2="14.224" y2="-1.016" layer="51"/>
<rectangle x1="18.796" y1="-1.524" x2="19.304" y2="-1.016" layer="51"/>
<rectangle x1="13.716" y1="1.016" x2="14.224" y2="1.524" layer="51"/>
<rectangle x1="16.256" y1="1.016" x2="16.764" y2="1.524" layer="51"/>
<rectangle x1="18.796" y1="1.016" x2="19.304" y2="1.524" layer="51"/>
<rectangle x1="21.336" y1="-1.524" x2="21.844" y2="-1.016" layer="51"/>
<rectangle x1="21.336" y1="1.016" x2="21.844" y2="1.524" layer="51"/>
</package>
<package name="MA08-1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-9.525" y1="1.27" x2="-8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="1.27" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-0.635" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-1.27" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-10.16" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-9.398" y="-2.921" size="1.27" layer="21" ratio="10">1</text>
<text x="8.255" y="1.651" size="1.27" layer="21" ratio="10">8</text>
<text x="-1.27" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="MA18-2">
<wire x1="3.81" y1="-22.86" x2="-3.81" y2="-22.86" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-15.24" x2="2.54" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-17.78" x2="2.54" y2="-17.78" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-20.32" x2="2.54" y2="-20.32" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-15.24" x2="-1.27" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-17.78" x2="-1.27" y2="-17.78" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-20.32" x2="-1.27" y2="-20.32" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-10.16" x2="2.54" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-12.7" x2="2.54" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-10.16" x2="-1.27" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-12.7" x2="-1.27" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="2.54" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-1.27" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-7.62" x2="-1.27" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="10.16" x2="2.54" y2="10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="7.62" x2="2.54" y2="7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="10.16" x2="-1.27" y2="10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="7.62" x2="-1.27" y2="7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-1.27" y2="5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="15.24" x2="2.54" y2="15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="12.7" x2="2.54" y2="12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="15.24" x2="-1.27" y2="15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="12.7" x2="-1.27" y2="12.7" width="0.6096" layer="94"/>
<wire x1="1.27" y1="20.32" x2="2.54" y2="20.32" width="0.6096" layer="94"/>
<wire x1="1.27" y1="17.78" x2="2.54" y2="17.78" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="20.32" x2="-1.27" y2="20.32" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="17.78" x2="-1.27" y2="17.78" width="0.6096" layer="94"/>
<wire x1="-3.81" y1="25.4" x2="-3.81" y2="-22.86" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-22.86" x2="3.81" y2="25.4" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="25.4" x2="3.81" y2="25.4" width="0.4064" layer="94"/>
<wire x1="1.27" y1="22.86" x2="2.54" y2="22.86" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="22.86" x2="-1.27" y2="22.86" width="0.6096" layer="94"/>
<text x="-3.81" y="-25.4" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="26.162" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-20.32" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-17.78" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-7.62" y="-20.32" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="4" x="-7.62" y="-17.78" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="6" x="-7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="7" x="7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="9" x="7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="-7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="10" x="-7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="11" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="13" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="15" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="12" x="-7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="14" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="16" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="17" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="19" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="18" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="20" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="21" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="23" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="25" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="22" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="24" x="-7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="26" x="-7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="27" x="7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="29" x="7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="28" x="-7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="30" x="-7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="31" x="7.62" y="17.78" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="33" x="7.62" y="20.32" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="32" x="-7.62" y="17.78" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="34" x="-7.62" y="20.32" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="35" x="7.62" y="22.86" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="36" x="-7.62" y="22.86" visible="pad" length="middle" direction="pas" swaplevel="1"/>
</symbol>
<symbol name="MA08-1">
<wire x1="3.81" y1="-10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="2.54" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="10.16" x2="2.54" y2="10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="7.62" x2="2.54" y2="7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="12.7" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-10.16" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="12.7" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<text x="-1.27" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="13.462" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MA18-2" prefix="SV" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="MA18-2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA18-2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="11" pad="11"/>
<connect gate="G$1" pin="12" pad="12"/>
<connect gate="G$1" pin="13" pad="13"/>
<connect gate="G$1" pin="14" pad="14"/>
<connect gate="G$1" pin="15" pad="15"/>
<connect gate="G$1" pin="16" pad="16"/>
<connect gate="G$1" pin="17" pad="17"/>
<connect gate="G$1" pin="18" pad="18"/>
<connect gate="G$1" pin="19" pad="19"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="20" pad="20"/>
<connect gate="G$1" pin="21" pad="21"/>
<connect gate="G$1" pin="22" pad="22"/>
<connect gate="G$1" pin="23" pad="23"/>
<connect gate="G$1" pin="24" pad="24"/>
<connect gate="G$1" pin="25" pad="25"/>
<connect gate="G$1" pin="26" pad="26"/>
<connect gate="G$1" pin="27" pad="27"/>
<connect gate="G$1" pin="28" pad="28"/>
<connect gate="G$1" pin="29" pad="29"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="30" pad="30"/>
<connect gate="G$1" pin="31" pad="31"/>
<connect gate="G$1" pin="32" pad="32"/>
<connect gate="G$1" pin="33" pad="33"/>
<connect gate="G$1" pin="34" pad="34"/>
<connect gate="G$1" pin="35" pad="35"/>
<connect gate="G$1" pin="36" pad="36"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MA08-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="MA08-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA08-1">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="1" pin="3" pad="3"/>
<connect gate="1" pin="4" pad="4"/>
<connect gate="1" pin="5" pad="5"/>
<connect gate="1" pin="6" pad="6"/>
<connect gate="1" pin="7" pad="7"/>
<connect gate="1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X01">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="PINHD1">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X1" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="DINA4_L">
<frame x1="0" y1="0" x2="264.16" y2="180.34" columns="4" rows="4" layer="94" border-left="no" border-top="no" border-right="no" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="DINA4_L" prefix="FRAME" uservalue="yes">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with extra doc field</description>
<gates>
<gate name="G$1" symbol="DINA4_L" x="0" y="0"/>
<gate name="G$2" symbol="DOCFIELD" x="162.56" y="0" addlevel="must"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-harting-h">
<description>&lt;b&gt;Harting Connectors&lt;/b&gt;&lt;p&gt;
PC board mounted ribbon cable connectors (IEC 52141), horizontal&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="26H">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<wire x1="-16.51" y1="11.303" x2="-13.97" y2="11.303" width="0.254" layer="21"/>
<wire x1="-13.97" y1="11.303" x2="-15.24" y2="8.763" width="0.254" layer="21"/>
<wire x1="-15.24" y1="8.763" x2="-16.51" y2="11.303" width="0.254" layer="21"/>
<wire x1="12.954" y1="11.049" x2="12.954" y2="12.065" width="0.1524" layer="21"/>
<wire x1="12.954" y1="11.049" x2="14.986" y2="11.049" width="0.1524" layer="21"/>
<wire x1="14.986" y1="12.065" x2="14.986" y2="11.049" width="0.1524" layer="21"/>
<wire x1="13.208" y1="7.112" x2="14.732" y2="7.112" width="0.1524" layer="21" curve="-180"/>
<wire x1="14.732" y1="7.112" x2="14.732" y2="5.588" width="0.1524" layer="21"/>
<wire x1="14.732" y1="4.826" x2="16.129" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="-1.651" x2="-26.162" y2="8.382" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="12.065" x2="-13.589" y2="12.065" width="0.1524" layer="21"/>
<wire x1="19.05" y1="15.494" x2="23.368" y2="15.494" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="15.494" x2="-18.4404" y2="15.0368" width="0.1524" layer="21" curve="-73.739795"/>
<wire x1="-18.4404" y1="15.0368" x2="-18.434" y2="15.013" width="0.1524" layer="21" curve="-2.224981"/>
<wire x1="-19.05" y1="15.494" x2="-23.368" y2="15.494" width="0.1524" layer="21"/>
<wire x1="18.434" y1="15.013" x2="18.4404" y2="15.0368" width="0.1524" layer="21" curve="-2.224981"/>
<wire x1="18.4404" y1="15.0368" x2="19.05" y2="15.494" width="0.1524" layer="21" curve="-73.739795"/>
<wire x1="17.145" y1="12.065" x2="17.8248" y2="12.6602" width="0.1524" layer="21" curve="82.409456"/>
<wire x1="17.8054" y1="12.5984" x2="18.4404" y2="15.0368" width="0.1524" layer="21"/>
<wire x1="-17.8248" y1="12.6602" x2="-17.145" y2="12.065" width="0.1524" layer="21" curve="82.409456"/>
<wire x1="-17.8054" y1="12.5984" x2="-18.4404" y2="15.0368" width="0.1524" layer="21"/>
<wire x1="23.368" y1="15.494" x2="23.9243" y2="15.0878" width="0.1524" layer="21" curve="-72.248491"/>
<wire x1="23.9268" y1="15.0876" x2="26.162" y2="8.382" width="0.1524" layer="21"/>
<wire x1="-23.9244" y1="15.0878" x2="-23.368" y2="15.4941" width="0.1524" layer="21" curve="-72.251141"/>
<wire x1="-23.9268" y1="15.0876" x2="-26.162" y2="8.382" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="-1.651" x2="-25.908" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="26.162" y1="-1.651" x2="26.162" y2="8.382" width="0.1524" layer="21"/>
<wire x1="26.162" y1="-1.651" x2="25.908" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="12.065" x2="-2.159" y2="5.588" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="12.065" x2="2.159" y2="12.065" width="0.1524" layer="21"/>
<wire x1="2.159" y1="12.065" x2="2.159" y2="5.588" width="0.1524" layer="21"/>
<wire x1="2.159" y1="12.065" x2="11.811" y2="12.065" width="0.1524" layer="21"/>
<wire x1="2.159" y1="5.588" x2="-2.159" y2="5.588" width="0.1524" layer="21"/>
<wire x1="2.159" y1="4.572" x2="-2.159" y2="4.572" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="5.588" x2="-2.159" y2="4.572" width="0.1524" layer="21"/>
<wire x1="2.159" y1="5.588" x2="2.159" y2="4.572" width="0.1524" layer="21"/>
<wire x1="13.208" y1="7.112" x2="13.208" y2="5.588" width="0.1524" layer="21"/>
<wire x1="13.208" y1="5.588" x2="13.208" y2="4.826" width="0.1524" layer="21"/>
<wire x1="13.208" y1="5.588" x2="14.732" y2="5.588" width="0.1524" layer="21"/>
<wire x1="14.732" y1="5.588" x2="14.732" y2="4.826" width="0.1524" layer="21"/>
<wire x1="16.129" y1="4.826" x2="16.129" y2="12.065" width="0.1524" layer="21"/>
<wire x1="16.129" y1="4.826" x2="16.129" y2="2.794" width="0.1524" layer="21"/>
<wire x1="16.129" y1="2.794" x2="11.811" y2="2.794" width="0.1524" layer="21"/>
<wire x1="17.272" y1="2.794" x2="17.272" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="17.272" y1="2.794" x2="16.129" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-17.272" y1="2.794" x2="-17.272" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-16.129" y1="-1.778" x2="-14.351" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="-17.272" y1="-1.778" x2="-16.129" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-14.351" y1="-1.778" x2="-13.589" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-13.589" y1="-1.778" x2="-11.811" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="-11.811" y1="-1.778" x2="-11.049" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-11.049" y1="-1.778" x2="-9.271" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="-9.271" y1="-1.778" x2="-8.509" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-8.509" y1="-1.778" x2="-6.731" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="-6.731" y1="-1.778" x2="-5.969" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="17.272" y1="-1.778" x2="16.129" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-4.191" y1="-1.778" x2="-5.969" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="-25.908" y1="-1.905" x2="-23.622" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="-1.778" x2="-21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="-1.778" x2="-18.542" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="25.908" y1="-1.905" x2="23.622" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="21.59" y1="-1.778" x2="21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="21.59" y1="-1.778" x2="18.542" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="19.304" y1="14.859" x2="19.304" y2="12.065" width="0.1524" layer="21"/>
<wire x1="19.304" y1="12.065" x2="23.114" y2="12.065" width="0.1524" layer="21"/>
<wire x1="23.114" y1="14.859" x2="23.114" y2="12.065" width="0.1524" layer="21"/>
<wire x1="23.114" y1="14.859" x2="19.304" y2="14.859" width="0.1524" layer="21"/>
<wire x1="-23.622" y1="-1.905" x2="-23.622" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-23.622" y1="-1.905" x2="-21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-18.542" y1="-1.778" x2="-18.542" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-18.542" y1="-1.778" x2="-17.272" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-23.622" y1="2.159" x2="-21.082" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-21.082" y1="3.81" x2="-18.542" y2="2.159" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-1.905" x2="23.622" y2="2.159" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-1.905" x2="21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="18.542" y1="-1.778" x2="18.542" y2="2.159" width="0.1524" layer="21"/>
<wire x1="18.542" y1="-1.778" x2="17.272" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="18.542" y1="2.159" x2="21.082" y2="3.81" width="0.1524" layer="21"/>
<wire x1="21.082" y1="3.81" x2="23.622" y2="2.159" width="0.1524" layer="21"/>
<wire x1="11.811" y1="4.826" x2="13.208" y2="4.826" width="0.1524" layer="21"/>
<wire x1="11.811" y1="4.826" x2="11.811" y2="12.065" width="0.1524" layer="21"/>
<wire x1="11.811" y1="12.065" x2="17.145" y2="12.065" width="0.1524" layer="21"/>
<wire x1="11.811" y1="4.826" x2="11.811" y2="2.794" width="0.1524" layer="21"/>
<wire x1="11.811" y1="2.794" x2="-9.271" y2="2.794" width="0.1524" layer="21"/>
<wire x1="0" y1="11.176" x2="0" y2="11.43" width="0.508" layer="21"/>
<wire x1="-13.589" y1="4.826" x2="-13.589" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-13.589" y1="12.065" x2="-12.446" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-12.446" y1="11.049" x2="-12.446" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-12.446" y1="12.065" x2="-10.414" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-12.446" y1="11.049" x2="-10.414" y2="11.049" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="12.065" x2="-10.414" y2="11.049" width="0.1524" layer="21"/>
<wire x1="-10.414" y1="12.065" x2="-9.271" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="4.826" x2="-9.271" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="12.065" x2="-2.159" y2="12.065" width="0.1524" layer="21"/>
<wire x1="-13.589" y1="4.826" x2="-12.192" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-13.589" y1="4.826" x2="-13.589" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-13.589" y1="2.794" x2="-17.272" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-12.192" y1="5.588" x2="-12.192" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-12.192" y1="5.588" x2="-10.668" y2="5.588" width="0.1524" layer="21"/>
<wire x1="-10.668" y1="5.588" x2="-10.668" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-10.668" y1="4.826" x2="-9.271" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="4.826" x2="-9.271" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-9.271" y1="2.794" x2="-13.589" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-12.192" y1="7.112" x2="-12.192" y2="5.588" width="0.1524" layer="21"/>
<wire x1="-10.668" y1="7.112" x2="-10.668" y2="5.588" width="0.1524" layer="21"/>
<wire x1="-12.192" y1="7.112" x2="-10.668" y2="7.112" width="0.1524" layer="21" curve="-180"/>
<wire x1="-4.191" y1="-1.778" x2="-3.429" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="-1.778" x2="-0.889" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="-1.778" x2="-3.429" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="0.889" y1="-1.778" x2="-0.889" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="0.889" y1="-1.778" x2="1.651" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="3.429" y1="-1.778" x2="1.651" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="3.429" y1="-1.778" x2="4.191" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="5.969" y1="-1.778" x2="4.191" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="5.969" y1="-1.778" x2="6.731" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="8.509" y1="-1.778" x2="6.731" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="8.509" y1="-1.778" x2="9.271" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="11.049" y1="-1.778" x2="9.271" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="11.049" y1="-1.778" x2="11.811" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="13.589" y1="-1.778" x2="11.811" y2="-1.778" width="0.1524" layer="51"/>
<wire x1="13.589" y1="-1.778" x2="14.351" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="16.129" y1="-1.778" x2="14.351" y2="-1.778" width="0.1524" layer="51"/>
<circle x="-21.082" y="0.5334" radius="2.286" width="0" layer="42"/>
<circle x="-21.082" y="0.5334" radius="2.286" width="0" layer="43"/>
<circle x="21.082" y="0.5334" radius="2.286" width="0" layer="42"/>
<circle x="21.082" y="0.5334" radius="2.286" width="0" layer="43"/>
<circle x="-21.082" y="0.5334" radius="1.3208" width="0.1524" layer="21"/>
<circle x="21.082" y="0.5334" radius="1.3208" width="0.1524" layer="21"/>
<circle x="22.352" y="8.382" radius="1.397" width="0.1524" layer="21"/>
<circle x="-22.352" y="8.382" radius="1.397" width="0.1524" layer="21"/>
<pad name="1" x="-15.24" y="-1.27" drill="0.9144"/>
<pad name="2" x="-15.24" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="3" x="-12.7" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="4" x="-12.7" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="5" x="-10.16" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="6" x="-10.16" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="7" x="-7.62" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="8" x="-7.62" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="9" x="-5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="10" x="-5.08" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="11" x="-2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="12" x="-2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="13" x="0" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="14" x="0" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="15" x="2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="16" x="2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="17" x="5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="18" x="5.08" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="19" x="7.62" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="20" x="7.62" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="21" x="10.16" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="22" x="10.16" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="23" x="12.7" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="24" x="12.7" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="25" x="15.24" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="26" x="15.24" y="1.27" drill="0.9144" shape="octagon"/>
<text x="-16.6878" y="-1.4224" size="1.27" layer="51" ratio="10">1</text>
<text x="-16.7132" y="0.6096" size="1.27" layer="51" ratio="10">2</text>
<text x="-15.2654" y="12.7" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.1054" y="12.7" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="19.939" y="12.7" size="1.524" layer="21" ratio="10">26</text>
<rectangle x1="-16.383" y1="10.795" x2="-14.097" y2="11.303" layer="21"/>
<rectangle x1="-16.129" y1="10.287" x2="-14.351" y2="10.795" layer="21"/>
<rectangle x1="-15.875" y1="9.779" x2="-14.605" y2="10.287" layer="21"/>
<rectangle x1="-15.621" y1="9.271" x2="-14.859" y2="9.779" layer="21"/>
<rectangle x1="-15.367" y1="9.017" x2="-15.113" y2="9.271" layer="21"/>
<rectangle x1="-0.254" y1="5.588" x2="0.254" y2="11.43" layer="21"/>
<hole x="-21.082" y="0.5334" drill="3.302"/>
<hole x="21.082" y="0.5334" drill="3.302"/>
</package>
</packages>
<symbols>
<symbol name="26P">
<wire x1="3.81" y1="-17.78" x2="-3.81" y2="-17.78" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="2.54" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-10.16" x2="2.54" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-12.7" x2="2.54" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-15.24" x2="2.54" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-1.27" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-7.62" x2="-1.27" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-10.16" x2="-1.27" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-12.7" x2="-1.27" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-15.24" x2="-1.27" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="7.62" x2="2.54" y2="7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="7.62" x2="-1.27" y2="7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-1.27" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-3.81" y1="17.78" x2="-3.81" y2="-17.78" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-17.78" x2="3.81" y2="17.78" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="17.78" x2="3.81" y2="17.78" width="0.4064" layer="94"/>
<wire x1="1.27" y1="15.24" x2="2.54" y2="15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="12.7" x2="2.54" y2="12.7" width="0.6096" layer="94"/>
<wire x1="1.27" y1="10.16" x2="2.54" y2="10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="15.24" x2="-1.27" y2="15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="12.7" x2="-1.27" y2="12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="10.16" x2="-1.27" y2="10.16" width="0.6096" layer="94"/>
<text x="-3.81" y="-20.32" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="18.542" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="9" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="4" x="-7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="6" x="-7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="8" x="-7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="10" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="11" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="13" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="15" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="17" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="19" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="12" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="14" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="16" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="18" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="20" x="-7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="21" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="23" x="7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="25" x="7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="22" x="-7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="24" x="-7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="26" x="-7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="26H" prefix="PL" uservalue="yes">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="26P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="26H">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="11" pad="11"/>
<connect gate="G$1" pin="12" pad="12"/>
<connect gate="G$1" pin="13" pad="13"/>
<connect gate="G$1" pin="14" pad="14"/>
<connect gate="G$1" pin="15" pad="15"/>
<connect gate="G$1" pin="16" pad="16"/>
<connect gate="G$1" pin="17" pad="17"/>
<connect gate="G$1" pin="18" pad="18"/>
<connect gate="G$1" pin="19" pad="19"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="20" pad="20"/>
<connect gate="G$1" pin="21" pad="21"/>
<connect gate="G$1" pin="22" pad="22"/>
<connect gate="G$1" pin="23" pad="23"/>
<connect gate="G$1" pin="24" pad="24"/>
<connect gate="G$1" pin="25" pad="25"/>
<connect gate="G$1" pin="26" pad="26"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="D22-D53" library="con-lstb" deviceset="MA18-2" device="" value="ARDUINO"/>
<part name="A8-A15" library="con-lstb" deviceset="MA08-1" device="" value="ARDUINO"/>
<part name="D14-D21" library="con-lstb" deviceset="MA08-1" device="" value="ARDUINO"/>
<part name="PIN-D3" library="pinhead" deviceset="PINHD-1X1" device="" value="ARDUINO"/>
<part name="PIN-3V3" library="pinhead" deviceset="PINHD-1X1" device="" value="ARDUINO"/>
<part name="RST" library="pinhead" deviceset="PINHD-1X1" device="" value="ARDUINO"/>
<part name="ALIM" library="con-molex" deviceset="22-?-02" device="27-2021"/>
<part name="FRAME1" library="frames" deviceset="DINA4_L" device="" value="RADIAL-V BUS BOARD"/>
<part name="PL1" library="con-harting-h" deviceset="26H" device="" value="vers Ext. Board"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="92.456" y="69.85" size="1.778" layer="91">14
15
16
17
18
19
20
21
22
23
24
25
X</text>
<text x="14.986" y="9.398" size="1.778" layer="91">Les pins imposées sont:
   I2C : SCL / SDA
   SPi  : MOSI / MISO / SCLK
   ISR : D3 / D18 / D19</text>
<text x="198.12" y="10.16" size="1.778" layer="91">DAVID</text>
<text x="112.776" y="69.85" size="1.778" layer="91">1
2
3
4
5
6
7
8
9
10
11
12
13</text>
</plain>
<instances>
<instance part="D22-D53" gate="G$1" x="187.96" y="93.98"/>
<instance part="A8-A15" gate="1" x="190.5" y="147.32" rot="MR0"/>
<instance part="D14-D21" gate="1" x="12.7" y="86.36" rot="MR180"/>
<instance part="PIN-D3" gate="G$1" x="190.5" y="58.42"/>
<instance part="PIN-3V3" gate="G$1" x="190.5" y="45.72"/>
<instance part="RST" gate="G$1" x="12.7" y="58.42" rot="MR0"/>
<instance part="ALIM" gate="-1" x="238.76" y="93.98"/>
<instance part="ALIM" gate="-2" x="238.76" y="91.44"/>
<instance part="FRAME1" gate="G$1" x="0" y="0"/>
<instance part="FRAME1" gate="G$2" x="162.56" y="0"/>
<instance part="PL1" gate="G$1" x="104.14" y="86.36"/>
</instances>
<busses>
</busses>
<nets>
<net name="SCL" class="0">
<segment>
<pinref part="D14-D21" gate="1" pin="8"/>
<wire x1="20.32" y1="76.2" x2="53.34" y2="76.2" width="0.1524" layer="91"/>
<label x="33.02" y="76.2" size="1.778" layer="95"/>
<wire x1="53.34" y1="76.2" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<wire x1="124.46" y1="63.5" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<label x="116.84" y="73.66" size="1.778" layer="95"/>
<wire x1="124.46" y1="63.5" x2="124.46" y2="73.66" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="3"/>
<wire x1="111.76" y1="73.66" x2="124.46" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<pinref part="D14-D21" gate="1" pin="7"/>
<wire x1="20.32" y1="78.74" x2="55.88" y2="78.74" width="0.1524" layer="91"/>
<label x="33.02" y="78.74" size="1.778" layer="95"/>
<wire x1="55.88" y1="73.66" x2="55.88" y2="78.74" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="4"/>
<wire x1="96.52" y1="73.66" x2="55.88" y2="73.66" width="0.1524" layer="91"/>
<label x="86.36" y="73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="A14" class="0">
<segment>
<pinref part="A8-A15" gate="1" pin="7"/>
<wire x1="182.88" y1="154.94" x2="53.34" y2="154.94" width="0.1524" layer="91"/>
<wire x1="53.34" y1="154.94" x2="50.8" y2="152.4" width="0.1524" layer="91"/>
<wire x1="50.8" y1="152.4" x2="50.8" y2="96.52" width="0.1524" layer="91"/>
<label x="167.64" y="154.94" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="22"/>
<wire x1="96.52" y1="96.52" x2="50.8" y2="96.52" width="0.1524" layer="91"/>
<label x="86.36" y="96.52" size="1.778" layer="95"/>
</segment>
</net>
<net name="A12" class="0">
<segment>
<pinref part="A8-A15" gate="1" pin="5"/>
<wire x1="182.88" y1="149.86" x2="55.88" y2="149.86" width="0.1524" layer="91"/>
<wire x1="55.88" y1="149.86" x2="53.34" y2="147.32" width="0.1524" layer="91"/>
<wire x1="53.34" y1="147.32" x2="53.34" y2="93.98" width="0.1524" layer="91"/>
<label x="167.64" y="149.86" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="20"/>
<wire x1="96.52" y1="93.98" x2="53.34" y2="93.98" width="0.1524" layer="91"/>
<label x="86.36" y="93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="D51-MOSI" class="0">
<segment>
<label x="167.64" y="111.76" size="1.778" layer="95"/>
<pinref part="D22-D53" gate="G$1" pin="32"/>
<wire x1="129.54" y1="111.76" x2="180.34" y2="111.76" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="25"/>
<wire x1="111.76" y1="101.6" x2="129.54" y2="101.6" width="0.1524" layer="91"/>
<wire x1="129.54" y1="101.6" x2="129.54" y2="111.76" width="0.1524" layer="91"/>
<label x="116.84" y="101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="2"/>
<wire x1="180.34" y1="73.66" x2="170.18" y2="73.66" width="0.1524" layer="91"/>
<wire x1="170.18" y1="73.66" x2="170.18" y2="66.04" width="0.1524" layer="91"/>
<wire x1="170.18" y1="66.04" x2="205.74" y2="66.04" width="0.1524" layer="91"/>
<wire x1="205.74" y1="66.04" x2="205.74" y2="71.12" width="0.1524" layer="91"/>
<pinref part="D22-D53" gate="G$1" pin="1"/>
<wire x1="205.74" y1="71.12" x2="205.74" y2="73.66" width="0.1524" layer="91"/>
<wire x1="205.74" y1="73.66" x2="195.58" y2="73.66" width="0.1524" layer="91"/>
<label x="218.44" y="71.12" size="1.778" layer="95"/>
<wire x1="205.74" y1="71.12" x2="231.14" y2="71.12" width="0.1524" layer="91"/>
<wire x1="231.14" y1="71.12" x2="231.14" y2="91.44" width="0.1524" layer="91"/>
<pinref part="ALIM" gate="-2" pin="S"/>
<wire x1="231.14" y1="91.44" x2="236.22" y2="91.44" width="0.1524" layer="91"/>
<junction x="205.74" y="71.12"/>
</segment>
</net>
<net name="D33" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="14"/>
<wire x1="180.34" y1="88.9" x2="154.94" y2="88.9" width="0.1524" layer="91"/>
<label x="167.64" y="88.9" size="1.778" layer="95"/>
<wire x1="154.94" y1="88.9" x2="154.94" y2="121.92" width="0.1524" layer="91"/>
<wire x1="154.94" y1="121.92" x2="68.58" y2="121.92" width="0.1524" layer="91"/>
<wire x1="68.58" y1="121.92" x2="68.58" y2="83.82" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="12"/>
<wire x1="68.58" y1="83.82" x2="96.52" y2="83.82" width="0.1524" layer="91"/>
<label x="86.36" y="83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="D35" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="16"/>
<wire x1="180.34" y1="91.44" x2="142.24" y2="91.44" width="0.1524" layer="91"/>
<label x="167.64" y="91.44" size="1.778" layer="95"/>
<wire x1="142.24" y1="91.44" x2="142.24" y2="83.82" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="11"/>
<wire x1="142.24" y1="83.82" x2="111.76" y2="83.82" width="0.1524" layer="91"/>
<label x="116.84" y="83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="D37" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="18"/>
<wire x1="180.34" y1="93.98" x2="157.48" y2="93.98" width="0.1524" layer="91"/>
<label x="167.64" y="93.98" size="1.778" layer="95"/>
<wire x1="157.48" y1="93.98" x2="157.48" y2="119.38" width="0.1524" layer="91"/>
<wire x1="157.48" y1="119.38" x2="71.12" y2="119.38" width="0.1524" layer="91"/>
<wire x1="71.12" y1="119.38" x2="71.12" y2="86.36" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="14"/>
<wire x1="71.12" y1="86.36" x2="96.52" y2="86.36" width="0.1524" layer="91"/>
<label x="86.36" y="86.36" size="1.778" layer="95"/>
</segment>
</net>
<net name="D39" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="20"/>
<wire x1="180.34" y1="96.52" x2="139.7" y2="96.52" width="0.1524" layer="91"/>
<label x="167.64" y="96.52" size="1.778" layer="95"/>
<wire x1="139.7" y1="96.52" x2="139.7" y2="86.36" width="0.1524" layer="91"/>
<label x="116.84" y="86.36" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="13"/>
<wire x1="111.76" y1="86.36" x2="139.7" y2="86.36" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D41" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="22"/>
<wire x1="180.34" y1="99.06" x2="160.02" y2="99.06" width="0.1524" layer="91"/>
<label x="167.64" y="99.06" size="1.778" layer="95"/>
<wire x1="160.02" y1="99.06" x2="160.02" y2="116.84" width="0.1524" layer="91"/>
<wire x1="160.02" y1="116.84" x2="73.66" y2="116.84" width="0.1524" layer="91"/>
<wire x1="73.66" y1="116.84" x2="73.66" y2="88.9" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="16"/>
<wire x1="73.66" y1="88.9" x2="96.52" y2="88.9" width="0.1524" layer="91"/>
<label x="86.36" y="88.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="D43" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="24"/>
<label x="167.64" y="101.6" size="1.778" layer="95"/>
<wire x1="137.16" y1="93.98" x2="137.16" y2="101.6" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="19"/>
<wire x1="111.76" y1="93.98" x2="137.16" y2="93.98" width="0.1524" layer="91"/>
<wire x1="180.34" y1="101.6" x2="137.16" y2="101.6" width="0.1524" layer="91"/>
<label x="116.84" y="93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="D45" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="26"/>
<wire x1="180.34" y1="104.14" x2="134.62" y2="104.14" width="0.1524" layer="91"/>
<label x="167.64" y="104.14" size="1.778" layer="95"/>
<wire x1="134.62" y1="104.14" x2="134.62" y2="96.52" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="21"/>
<wire x1="111.76" y1="96.52" x2="134.62" y2="96.52" width="0.1524" layer="91"/>
<label x="116.84" y="96.52" size="1.778" layer="95"/>
</segment>
</net>
<net name="D47" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="28"/>
<wire x1="180.34" y1="106.68" x2="162.56" y2="106.68" width="0.1524" layer="91"/>
<label x="167.64" y="106.68" size="1.778" layer="95"/>
<wire x1="162.56" y1="106.68" x2="162.56" y2="109.22" width="0.1524" layer="91"/>
<wire x1="162.56" y1="109.22" x2="76.2" y2="109.22" width="0.1524" layer="91"/>
<wire x1="76.2" y1="109.22" x2="76.2" y2="99.06" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="24"/>
<wire x1="76.2" y1="99.06" x2="96.52" y2="99.06" width="0.1524" layer="91"/>
<label x="86.36" y="99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="D31" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="12"/>
<wire x1="180.34" y1="86.36" x2="144.78" y2="86.36" width="0.1524" layer="91"/>
<label x="167.64" y="86.36" size="1.778" layer="95"/>
<wire x1="144.78" y1="86.36" x2="144.78" y2="81.28" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="9"/>
<wire x1="111.76" y1="81.28" x2="144.78" y2="81.28" width="0.1524" layer="91"/>
<label x="116.84" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="D29" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="10"/>
<wire x1="180.34" y1="83.82" x2="152.4" y2="83.82" width="0.1524" layer="91"/>
<label x="167.64" y="83.82" size="1.778" layer="95"/>
<wire x1="152.4" y1="83.82" x2="152.4" y2="124.46" width="0.1524" layer="91"/>
<wire x1="152.4" y1="124.46" x2="66.04" y2="124.46" width="0.1524" layer="91"/>
<wire x1="66.04" y1="124.46" x2="66.04" y2="81.28" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="10"/>
<wire x1="66.04" y1="81.28" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
<label x="86.36" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="D27" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="8"/>
<wire x1="180.34" y1="81.28" x2="147.32" y2="81.28" width="0.1524" layer="91"/>
<label x="167.64" y="81.28" size="1.778" layer="95"/>
<wire x1="147.32" y1="81.28" x2="147.32" y2="78.74" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="7"/>
<wire x1="111.76" y1="78.74" x2="147.32" y2="78.74" width="0.1524" layer="91"/>
<label x="116.84" y="78.74" size="1.778" layer="95"/>
</segment>
</net>
<net name="D25" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="6"/>
<wire x1="180.34" y1="78.74" x2="149.86" y2="78.74" width="0.1524" layer="91"/>
<label x="167.64" y="78.74" size="1.778" layer="95"/>
<wire x1="149.86" y1="78.74" x2="149.86" y2="127" width="0.1524" layer="91"/>
<wire x1="149.86" y1="127" x2="63.5" y2="127" width="0.1524" layer="91"/>
<wire x1="63.5" y1="127" x2="63.5" y2="78.74" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="8"/>
<wire x1="63.5" y1="78.74" x2="96.52" y2="78.74" width="0.1524" layer="91"/>
<label x="86.36" y="78.74" size="1.778" layer="95"/>
</segment>
</net>
<net name="D23" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="4"/>
<wire x1="180.34" y1="76.2" x2="111.76" y2="76.2" width="0.1524" layer="91"/>
<label x="167.64" y="76.2" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="5"/>
<label x="116.84" y="76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="D52-SCLK" class="0">
<segment>
<wire x1="132.08" y1="99.06" x2="132.08" y2="129.54" width="0.1524" layer="91"/>
<pinref part="D22-D53" gate="G$1" pin="33"/>
<wire x1="195.58" y1="114.3" x2="210.82" y2="114.3" width="0.1524" layer="91"/>
<wire x1="210.82" y1="114.3" x2="210.82" y2="129.54" width="0.1524" layer="91"/>
<wire x1="210.82" y1="129.54" x2="132.08" y2="129.54" width="0.1524" layer="91"/>
<label x="167.64" y="129.54" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="23"/>
<wire x1="111.76" y1="99.06" x2="132.08" y2="99.06" width="0.1524" layer="91"/>
<label x="116.84" y="99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="D50-MISO" class="0">
<segment>
<pinref part="D22-D53" gate="G$1" pin="31"/>
<wire x1="195.58" y1="111.76" x2="213.36" y2="111.76" width="0.1524" layer="91"/>
<wire x1="213.36" y1="111.76" x2="213.36" y2="132.08" width="0.1524" layer="91"/>
<wire x1="213.36" y1="132.08" x2="55.88" y2="132.08" width="0.1524" layer="91"/>
<wire x1="55.88" y1="132.08" x2="55.88" y2="101.6" width="0.1524" layer="91"/>
<wire x1="96.52" y1="101.6" x2="55.88" y2="101.6" width="0.1524" layer="91"/>
<label x="167.64" y="132.08" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="26"/>
<label x="78.74" y="101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND-ARD" class="0">
<segment>
<wire x1="205.74" y1="116.84" x2="205.74" y2="119.38" width="0.1524" layer="91"/>
<wire x1="205.74" y1="119.38" x2="205.74" y2="121.92" width="0.1524" layer="91"/>
<wire x1="205.74" y1="121.92" x2="170.18" y2="121.92" width="0.1524" layer="91"/>
<wire x1="170.18" y1="121.92" x2="170.18" y2="116.84" width="0.1524" layer="91"/>
<pinref part="D22-D53" gate="G$1" pin="36"/>
<wire x1="180.34" y1="116.84" x2="170.18" y2="116.84" width="0.1524" layer="91"/>
<pinref part="D22-D53" gate="G$1" pin="35"/>
<wire x1="205.74" y1="116.84" x2="195.58" y2="116.84" width="0.1524" layer="91"/>
<label x="215.9" y="119.38" size="1.778" layer="95"/>
<wire x1="205.74" y1="119.38" x2="231.14" y2="119.38" width="0.1524" layer="91"/>
<wire x1="231.14" y1="119.38" x2="231.14" y2="93.98" width="0.1524" layer="91"/>
<pinref part="ALIM" gate="-1" pin="S"/>
<wire x1="231.14" y1="93.98" x2="236.22" y2="93.98" width="0.1524" layer="91"/>
<junction x="205.74" y="119.38"/>
</segment>
</net>
<net name="RST" class="0">
<segment>
<pinref part="RST" gate="G$1" pin="1"/>
<wire x1="15.24" y1="58.42" x2="63.5" y2="58.42" width="0.1524" layer="91"/>
<wire x1="63.5" y1="58.42" x2="63.5" y2="76.2" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="6"/>
<wire x1="96.52" y1="76.2" x2="63.5" y2="76.2" width="0.1524" layer="91"/>
<label x="86.36" y="76.2" size="1.778" layer="95"/>
<label x="33.02" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="D3" class="0">
<segment>
<pinref part="PIN-D3" gate="G$1" pin="1"/>
<wire x1="187.96" y1="58.42" x2="139.7" y2="58.42" width="0.1524" layer="91"/>
<wire x1="139.7" y1="58.42" x2="137.16" y2="60.96" width="0.1524" layer="91"/>
<label x="167.64" y="58.42" size="1.778" layer="95"/>
<wire x1="137.16" y1="60.96" x2="137.16" y2="91.44" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="17"/>
<label x="116.84" y="91.44" size="1.778" layer="95"/>
<wire x1="137.16" y1="91.44" x2="111.76" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="3V3" class="0">
<segment>
<pinref part="PIN-3V3" gate="G$1" pin="1"/>
<wire x1="187.96" y1="45.72" x2="137.16" y2="45.72" width="0.1524" layer="91"/>
<wire x1="137.16" y1="45.72" x2="134.62" y2="48.26" width="0.1524" layer="91"/>
<wire x1="134.62" y1="48.26" x2="134.62" y2="71.12" width="0.1524" layer="91"/>
<label x="167.64" y="45.72" size="1.778" layer="95"/>
<label x="116.84" y="71.12" size="1.778" layer="95"/>
<pinref part="PL1" gate="G$1" pin="1"/>
<wire x1="134.62" y1="71.12" x2="111.76" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D18" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="18"/>
<wire x1="55.88" y1="91.44" x2="96.52" y2="91.44" width="0.1524" layer="91"/>
<label x="86.36" y="91.44" size="1.778" layer="95"/>
<pinref part="D14-D21" gate="1" pin="5"/>
<wire x1="20.32" y1="83.82" x2="55.88" y2="83.82" width="0.1524" layer="91"/>
<label x="33.02" y="83.82" size="1.778" layer="95"/>
<wire x1="55.88" y1="91.44" x2="55.88" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D19" class="0">
<segment>
<wire x1="124.46" y1="45.72" x2="127" y2="48.26" width="0.1524" layer="91"/>
<wire x1="53.34" y1="45.72" x2="124.46" y2="45.72" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="15"/>
<wire x1="127" y1="88.9" x2="111.76" y2="88.9" width="0.1524" layer="91"/>
<label x="116.84" y="88.9" size="1.778" layer="95"/>
<wire x1="127" y1="48.26" x2="127" y2="88.9" width="0.1524" layer="91"/>
<wire x1="53.34" y1="45.72" x2="50.8" y2="48.26" width="0.1524" layer="91"/>
<wire x1="50.8" y1="48.26" x2="50.8" y2="81.28" width="0.1524" layer="91"/>
<pinref part="D14-D21" gate="1" pin="6"/>
<wire x1="20.32" y1="81.28" x2="50.8" y2="81.28" width="0.1524" layer="91"/>
<label x="33.02" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
