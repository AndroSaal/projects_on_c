TEST_FILE=../tests/test/test_5.txt
EXECUTABLE_FILE=./s21_cat
TEST_QUALITY=0
SUCC_COUNTS=0
FAIL_COUNTS=0
VALGRIND_FLAGS="--tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all"
echo " " > log.txt
echo " " > log_leak.txt
function assert {
    ((TEST_QUALITY++))
    echo "TEST №$TEST_QUALITY STARTED" >> log.txt
    echo "TEST №$TEST_QUALITY STARTED" >> log_leak.txt
    cat $CAT_ARGS $TEST_FILE > cat_result.txt
    $EXECUTABLE_FILE $CAT_ARGS $TEST_FILE > s21_cat_result.txt
    valgrind $VALGRIND_FLAGS $EXECUTABLE_FILE $CAT_ARGS $TEST_FILE | grep -E ERROR >> log_leak.txt
    echo "\n\n\n" >> log_leak.txt
    diff cat_result.txt s21_cat_result.txt > cat_rusult.txt
    if [ $? -ne 0 ]; then
        echo "TEST $TEST_QUALITY FAILED"
        echo "TEST $TEST_QUALITY FAILED" >> log.txt
        echo "EXPECTED OUTPUT FROM CAT:" >> log.txt
        cat $CAT_ARGS $TEST_FILE >> log.txt
        echo "" >> log.txt
        echo "HAVE OUTPUT FROM s21_CAT:" >> log.txt
        $EXECUTABLE_FILE $CAT_ARGS $TEST_FILE >> log.txt
        ((FAIL_COUNTS++))
        exit
    else
        echo "TEST $TEST_QUALITY OK"
        echo "TEST $TEST_QUALITY OK" >> log.txt
        ((SUCC_COUNTS++))

    fi
    rm cat_result.txt s21_cat_result.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo " " >> log.txt
    echo "SUCCESS $SUCC_COUNTS/$TEST_QUALITY"
    echo "FAIL $FAIL_COUNTS/$TEST_QUALITY"

}

CAT_ARGS="-e"
assert 1

CAT_ARGS="-E"
assert 2

CAT_ARGS="-b"
assert 3

CAT_ARGS="--number-nonblank"
assert 4

CAT_ARGS="-n"
assert 5

CAT_ARGS="--number"
assert 6

CAT_ARGS="-s"
assert 7

CAT_ARGS="--squeeze-blank"
assert 8

CAT_ARGS="-t"
assert 9

CAT_ARGS="-T"
assert 10

CAT_ARGS="-v"
assert 11

CAT_ARGS="-e -E"
assert 12

CAT_ARGS="-e -b"
assert 13

CAT_ARGS="-e --number-nonblank"
assert 14

CAT_ARGS="-e -n"
assert 15

CAT_ARGS="-e --number"
assert 16

CAT_ARGS="-e -s"
assert 17

CAT_ARGS="-e --squeeze-blank"
assert 18

CAT_ARGS="-e -t"
assert 19

CAT_ARGS="-e -T"
assert 20

CAT_ARGS="-e -v"
assert 21

CAT_ARGS="-E -b"
assert 22

CAT_ARGS="-E --number-nonblank"
assert 23

CAT_ARGS="-E -n"
assert 24

CAT_ARGS="-E --number"
assert 25

CAT_ARGS="-E -s"
assert 26

CAT_ARGS="-E --squeeze-blank"
assert 27

CAT_ARGS="-E -t"
assert 28

CAT_ARGS="-E -T"
assert 29

CAT_ARGS="-E -v"
assert 30

CAT_ARGS="-b --number-nonblank"
assert 31

CAT_ARGS="-b -n"
assert 32

CAT_ARGS="-b --number"
assert 33

CAT_ARGS="-b -s"
assert 34

CAT_ARGS="-b --squeeze-blank"
assert 35

CAT_ARGS="-b -t"
assert 36

CAT_ARGS="-b -T"
assert 37

CAT_ARGS="-b -v"
assert 38

CAT_ARGS="--number-nonblank -n"
assert 39

CAT_ARGS="--number-nonblank --number"
assert 40

CAT_ARGS="--number-nonblank -s"
assert 41

CAT_ARGS="--number-nonblank --squeeze-blank"
assert 42

CAT_ARGS="--number-nonblank -t"
assert 43

CAT_ARGS="--number-nonblank -T"
assert 44

CAT_ARGS="--number-nonblank -v"
assert 45

CAT_ARGS="-n --number"
assert 46

CAT_ARGS="-n -s"
assert 47

CAT_ARGS="-n --squeeze-blank"
assert 48

CAT_ARGS="-n -t"
assert 49

CAT_ARGS="-n -T"
assert 50

CAT_ARGS="-n -v"
assert 51

CAT_ARGS="--number -s"
assert 52

CAT_ARGS="--number --squeeze-blank"
assert 53

CAT_ARGS="--number -t"
assert 54

CAT_ARGS="--number -T"
assert 55

CAT_ARGS="--number -v"
assert 56

CAT_ARGS="-s --squeeze-blank"
assert 57

CAT_ARGS="-s -t"
assert 58

CAT_ARGS="-s -T"
assert 59

CAT_ARGS="-s -v"
assert 60

CAT_ARGS="--squeeze-blank -t"
assert 61

CAT_ARGS="--squeeze-blank -T"
assert 62

CAT_ARGS="--squeeze-blank -v"
assert 63

CAT_ARGS="-t -T"
assert 64

CAT_ARGS="-t -v"
assert 65

CAT_ARGS="-T -v"
assert 66

CAT_ARGS="-e -E -b"
assert 67

CAT_ARGS="-e -E --number-nonblank"
assert 68

CAT_ARGS="-e -E -n"
assert 69

CAT_ARGS="-e -E --number"
assert 70

CAT_ARGS="-e -E -s"
assert 71

CAT_ARGS="-e -E --squeeze-blank"
assert 72

CAT_ARGS="-e -E -t"
assert 73

CAT_ARGS="-e -E -T"
assert 74

CAT_ARGS="-e -E -v"
assert 75

CAT_ARGS="-e -b --number-nonblank"
assert 76

CAT_ARGS="-e -b -n"
assert 77

CAT_ARGS="-e -b --number"
assert 78

CAT_ARGS="-e -b -s"
assert 79

CAT_ARGS="-e -b --squeeze-blank"
assert 80

CAT_ARGS="-e -b -t"
assert 81

CAT_ARGS="-e -b -T"
assert 82

CAT_ARGS="-e -b -v"
assert 83

CAT_ARGS="-e --number-nonblank -n"
assert 84

CAT_ARGS="-e --number-nonblank --number"
assert 85

CAT_ARGS="-e --number-nonblank -s"
assert 86

CAT_ARGS="-e --number-nonblank --squeeze-blank"
assert 87

CAT_ARGS="-e --number-nonblank -t"
assert 88

CAT_ARGS="-e --number-nonblank -T"
assert 89

CAT_ARGS="-e --number-nonblank -v"
assert 90

CAT_ARGS="-e -n --number"
assert 91

CAT_ARGS="-e -n -s"
assert 92

CAT_ARGS="-e -n --squeeze-blank"
assert 93

CAT_ARGS="-e -n -t"
assert 94

CAT_ARGS="-e -n -T"
assert 95

CAT_ARGS="-e -n -v"
assert 96

CAT_ARGS="-e --number -s"
assert 97

CAT_ARGS="-e --number --squeeze-blank"
assert 98

CAT_ARGS="-e --number -t"
assert 99

CAT_ARGS="-e --number -T"
assert 100

CAT_ARGS="-e --number -v"
assert 101

CAT_ARGS="-e -s --squeeze-blank"
assert 102

CAT_ARGS="-e -s -t"
assert 103

CAT_ARGS="-e -s -T"
assert 104

CAT_ARGS="-e -s -v"
assert 105

CAT_ARGS="-e --squeeze-blank -t"
assert 106

CAT_ARGS="-e --squeeze-blank -T"
assert 107

CAT_ARGS="-e --squeeze-blank -v"
assert 108

CAT_ARGS="-e -t -T"
assert 109

CAT_ARGS="-e -t -v"
assert 110

CAT_ARGS="-e -T -v"
assert 111

CAT_ARGS="-E -b --number-nonblank"
assert 112

CAT_ARGS="-E -b -n"
assert 113

CAT_ARGS="-E -b --number"
assert 114

CAT_ARGS="-E -b -s"
assert 115

CAT_ARGS="-E -b --squeeze-blank"
assert 116

CAT_ARGS="-E -b -t"
assert 117

CAT_ARGS="-E -b -T"
assert 118

CAT_ARGS="-E -b -v"
assert 119

CAT_ARGS="-E --number-nonblank -n"
assert 120

CAT_ARGS="-E --number-nonblank --number"
assert 121

CAT_ARGS="-E --number-nonblank -s"
assert 122

CAT_ARGS="-E --number-nonblank --squeeze-blank"
assert 123

CAT_ARGS="-E --number-nonblank -t"
assert 124

CAT_ARGS="-E --number-nonblank -T"
assert 125

CAT_ARGS="-E --number-nonblank -v"
assert 126

CAT_ARGS="-E -n --number"
assert 127

CAT_ARGS="-E -n -s"
assert 128

CAT_ARGS="-E -n --squeeze-blank"
assert 129

CAT_ARGS="-E -n -t"
assert 130

CAT_ARGS="-E -n -T"
assert 131

CAT_ARGS="-E -n -v"
assert 132

CAT_ARGS="-E --number -s"
assert 133

CAT_ARGS="-E --number --squeeze-blank"
assert 134

CAT_ARGS="-E --number -t"
assert 135

CAT_ARGS="-E --number -T"
assert 136

CAT_ARGS="-E --number -v"
assert 137

CAT_ARGS="-E -s --squeeze-blank"
assert 138

CAT_ARGS="-E -s -t"
assert 139

CAT_ARGS="-E -s -T"
assert 140

CAT_ARGS="-E -s -v"
assert 141

CAT_ARGS="-E --squeeze-blank -t"
assert 142

CAT_ARGS="-E --squeeze-blank -T"
assert 143

CAT_ARGS="-E --squeeze-blank -v"
assert 144

CAT_ARGS="-E -t -T"
assert 145

CAT_ARGS="-E -t -v"
assert 146

CAT_ARGS="-E -T -v"
assert 147

CAT_ARGS="-b --number-nonblank -n"
assert 148

CAT_ARGS="-b --number-nonblank --number"
assert 149

CAT_ARGS="-b --number-nonblank -s"
assert 150

CAT_ARGS="-b --number-nonblank --squeeze-blank"
assert 151

CAT_ARGS="-b --number-nonblank -t"
assert 152

CAT_ARGS="-b --number-nonblank -T"
assert 153

CAT_ARGS="-b --number-nonblank -v"
assert 154

CAT_ARGS="-b -n --number"
assert 155

CAT_ARGS="-b -n -s"
assert 156

CAT_ARGS="-b -n --squeeze-blank"
assert 157

CAT_ARGS="-b -n -t"
assert 158

CAT_ARGS="-b -n -T"
assert 159

CAT_ARGS="-b -n -v"
assert 160

CAT_ARGS="-b --number -s"
assert 161

CAT_ARGS="-b --number --squeeze-blank"
assert 162

CAT_ARGS="-b --number -t"
assert 163

CAT_ARGS="-b --number -T"
assert 164

CAT_ARGS="-b --number -v"
assert 165

CAT_ARGS="-b -s --squeeze-blank"
assert 166

CAT_ARGS="-b -s -t"
assert 167

CAT_ARGS="-b -s -T"
assert 168

CAT_ARGS="-b -s -v"
assert 169

CAT_ARGS="-b --squeeze-blank -t"
assert 170

CAT_ARGS="-b --squeeze-blank -T"
assert 171

CAT_ARGS="-b --squeeze-blank -v"
assert 172

CAT_ARGS="-b -t -T"
assert 173

CAT_ARGS="-b -t -v"
assert 174

CAT_ARGS="-b -T -v"
assert 175

CAT_ARGS="--number-nonblank -n --number"
assert 176

CAT_ARGS="--number-nonblank -n -s"
assert 177

CAT_ARGS="--number-nonblank -n --squeeze-blank"
assert 178

CAT_ARGS="--number-nonblank -n -t"
assert 179

CAT_ARGS="--number-nonblank -n -T"
assert 180

CAT_ARGS="--number-nonblank -n -v"
assert 181

CAT_ARGS="--number-nonblank --number -s"
assert 182

CAT_ARGS="--number-nonblank --number --squeeze-blank"
assert 183

CAT_ARGS="--number-nonblank --number -t"
assert 184

CAT_ARGS="--number-nonblank --number -T"
assert 185

CAT_ARGS="--number-nonblank --number -v"
assert 186

CAT_ARGS="--number-nonblank -s --squeeze-blank"
assert 187

CAT_ARGS="--number-nonblank -s -t"
assert 188

CAT_ARGS="--number-nonblank -s -T"
assert 189

CAT_ARGS="--number-nonblank -s -v"
assert 190

CAT_ARGS="--number-nonblank --squeeze-blank -t"
assert 191

CAT_ARGS="--number-nonblank --squeeze-blank -T"
assert 192

CAT_ARGS="--number-nonblank --squeeze-blank -v"
assert 193

CAT_ARGS="--number-nonblank -t -T"
assert 194

CAT_ARGS="--number-nonblank -t -v"
assert 195

CAT_ARGS="--number-nonblank -T -v"
assert 196

CAT_ARGS="-n --number -s"
assert 197

CAT_ARGS="-n --number --squeeze-blank"
assert 198

CAT_ARGS="-n --number -t"
assert 199

CAT_ARGS="-n --number -T"
assert 200

CAT_ARGS="-n --number -v"
assert 201

CAT_ARGS="-n -s --squeeze-blank"
assert 202

CAT_ARGS="-n -s -t"
assert 203

CAT_ARGS="-n -s -T"
assert 204

CAT_ARGS="-n -s -v"
assert 205

CAT_ARGS="-n --squeeze-blank -t"
assert 206

CAT_ARGS="-n --squeeze-blank -T"
assert 207

CAT_ARGS="-n --squeeze-blank -v"
assert 208

CAT_ARGS="-n -t -T"
assert 209

CAT_ARGS="-n -t -v"
assert 210

CAT_ARGS="-n -T -v"
assert 211

CAT_ARGS="--number -s --squeeze-blank"
assert 212

CAT_ARGS="--number -s -t"
assert 213

CAT_ARGS="--number -s -T"
assert 214

CAT_ARGS="--number -s -v"
assert 215

CAT_ARGS="--number --squeeze-blank -t"
assert 216

CAT_ARGS="--number --squeeze-blank -T"
assert 217

CAT_ARGS="--number --squeeze-blank -v"
assert 218

CAT_ARGS="--number -t -T"
assert 219

CAT_ARGS="--number -t -v"
assert 220

CAT_ARGS="--number -T -v"
assert 221

CAT_ARGS="-s --squeeze-blank -t"
assert 222

CAT_ARGS="-s --squeeze-blank -T"
assert 223

CAT_ARGS="-s --squeeze-blank -v"
assert 224

CAT_ARGS="-s -t -T"
assert 225

CAT_ARGS="-s -t -v"
assert 226

CAT_ARGS="-s -T -v"
assert 227

CAT_ARGS="--squeeze-blank -t -T"
assert 228

CAT_ARGS="--squeeze-blank -t -v"
assert 229

CAT_ARGS="--squeeze-blank -T -v"
assert 230

CAT_ARGS="-t -T -v"
assert 231

CAT_ARGS="-e -E -b --number-nonblank"
assert 232

CAT_ARGS="-e -E -b -n"
assert 233

CAT_ARGS="-e -E -b --number"
assert 234

CAT_ARGS="-e -E -b -s"
assert 235

CAT_ARGS="-e -E -b --squeeze-blank"
assert 236

CAT_ARGS="-e -E -b -t"
assert 237

CAT_ARGS="-e -E -b -T"
assert 238

CAT_ARGS="-e -E -b -v"
assert 239

CAT_ARGS="-e -E --number-nonblank -n"
assert 240

CAT_ARGS="-e -E --number-nonblank --number"
assert 241

CAT_ARGS="-e -E --number-nonblank -s"
assert 242

CAT_ARGS="-e -E --number-nonblank --squeeze-blank"
assert 243

CAT_ARGS="-e -E --number-nonblank -t"
assert 244

CAT_ARGS="-e -E --number-nonblank -T"
assert 245

CAT_ARGS="-e -E --number-nonblank -v"
assert 246

CAT_ARGS="-e -E -n --number"
assert 247

CAT_ARGS="-e -E -n -s"
assert 248

CAT_ARGS="-e -E -n --squeeze-blank"
assert 249

CAT_ARGS="-e -E -n -t"
assert 250

CAT_ARGS="-e -E -n -T"
assert 251

CAT_ARGS="-e -E -n -v"
assert 252

CAT_ARGS="-e -E --number -s"
assert 253

CAT_ARGS="-e -E --number --squeeze-blank"
assert 254

CAT_ARGS="-e -E --number -t"
assert 255

CAT_ARGS="-e -E --number -T"
assert 256

CAT_ARGS="-e -E --number -v"
assert 257

CAT_ARGS="-e -E -s --squeeze-blank"
assert 258

CAT_ARGS="-e -E -s -t"
assert 259

CAT_ARGS="-e -E -s -T"
assert 260

CAT_ARGS="-e -E -s -v"
assert 261

CAT_ARGS="-e -E --squeeze-blank -t"
assert 262

CAT_ARGS="-e -E --squeeze-blank -T"
assert 263

CAT_ARGS="-e -E --squeeze-blank -v"
assert 264

CAT_ARGS="-e -E -t -T"
assert 265

CAT_ARGS="-e -E -t -v"
assert 266

CAT_ARGS="-e -E -T -v"
assert 267

CAT_ARGS="-e -b --number-nonblank -n"
assert 268

CAT_ARGS="-e -b --number-nonblank --number"
assert 269

CAT_ARGS="-e -b --number-nonblank -s"
assert 270

CAT_ARGS="-e -b --number-nonblank --squeeze-blank"
assert 271

CAT_ARGS="-e -b --number-nonblank -t"
assert 272

CAT_ARGS="-e -b --number-nonblank -T"
assert 273

CAT_ARGS="-e -b --number-nonblank -v"
assert 274

CAT_ARGS="-e -b -n --number"
assert 275

CAT_ARGS="-e -b -n -s"
assert 276

CAT_ARGS="-e -b -n --squeeze-blank"
assert 277

CAT_ARGS="-e -b -n -t"
assert 278

CAT_ARGS="-e -b -n -T"
assert 279

CAT_ARGS="-e -b -n -v"
assert 280

CAT_ARGS="-e -b --number -s"
assert 281

CAT_ARGS="-e -b --number --squeeze-blank"
assert 282

CAT_ARGS="-e -b --number -t"
assert 283

CAT_ARGS="-e -b --number -T"
assert 284

CAT_ARGS="-e -b --number -v"
assert 285

CAT_ARGS="-e -b -s --squeeze-blank"
assert 286

CAT_ARGS="-e -b -s -t"
assert 287

CAT_ARGS="-e -b -s -T"
assert 288

CAT_ARGS="-e -b -s -v"
assert 289

CAT_ARGS="-e -b --squeeze-blank -t"
assert 290

CAT_ARGS="-e -b --squeeze-blank -T"
assert 291

CAT_ARGS="-e -b --squeeze-blank -v"
assert 292

CAT_ARGS="-e -b -t -T"
assert 293

CAT_ARGS="-e -b -t -v"
assert 294

CAT_ARGS="-e -b -T -v"
assert 295

CAT_ARGS="-e --number-nonblank -n --number"
assert 296

CAT_ARGS="-e --number-nonblank -n -s"
assert 297

CAT_ARGS="-e --number-nonblank -n --squeeze-blank"
assert 298

CAT_ARGS="-e --number-nonblank -n -t"
assert 299

CAT_ARGS="-e --number-nonblank -n -T"
assert 300

CAT_ARGS="-e --number-nonblank -n -v"
assert 301

CAT_ARGS="-e --number-nonblank --number -s"
assert 302

CAT_ARGS="-e --number-nonblank --number --squeeze-blank"
assert 303

CAT_ARGS="-e --number-nonblank --number -t"
assert 304

CAT_ARGS="-e --number-nonblank --number -T"
assert 305

CAT_ARGS="-e --number-nonblank --number -v"
assert 306

CAT_ARGS="-e --number-nonblank -s --squeeze-blank"
assert 307

CAT_ARGS="-e --number-nonblank -s -t"
assert 308

CAT_ARGS="-e --number-nonblank -s -T"
assert 309

CAT_ARGS="-e --number-nonblank -s -v"
assert 310

CAT_ARGS="-e --number-nonblank --squeeze-blank -t"
assert 311

CAT_ARGS="-e --number-nonblank --squeeze-blank -T"
assert 312

CAT_ARGS="-e --number-nonblank --squeeze-blank -v"
assert 313

CAT_ARGS="-e --number-nonblank -t -T"
assert 314

CAT_ARGS="-e --number-nonblank -t -v"
assert 315

CAT_ARGS="-e --number-nonblank -T -v"
assert 316

CAT_ARGS="-e -n --number -s"
assert 317

CAT_ARGS="-e -n --number --squeeze-blank"
assert 318

CAT_ARGS="-e -n --number -t"
assert 319

CAT_ARGS="-e -n --number -T"
assert 320

CAT_ARGS="-e -n --number -v"
assert 321

CAT_ARGS="-e -n -s --squeeze-blank"
assert 322

CAT_ARGS="-e -n -s -t"
assert 323

CAT_ARGS="-e -n -s -T"
assert 324

CAT_ARGS="-e -n -s -v"
assert 325

CAT_ARGS="-e -n --squeeze-blank -t"
assert 326

CAT_ARGS="-e -n --squeeze-blank -T"
assert 327

CAT_ARGS="-e -n --squeeze-blank -v"
assert 328

CAT_ARGS="-e -n -t -T"
assert 329

CAT_ARGS="-e -n -t -v"
assert 330

CAT_ARGS="-e -n -T -v"
assert 331

CAT_ARGS="-e --number -s --squeeze-blank"
assert 332

CAT_ARGS="-e --number -s -t"
assert 333

CAT_ARGS="-e --number -s -T"
assert 334

CAT_ARGS="-e --number -s -v"
assert 335

CAT_ARGS="-e --number --squeeze-blank -t"
assert 336

CAT_ARGS="-e --number --squeeze-blank -T"
assert 337

CAT_ARGS="-e --number --squeeze-blank -v"
assert 338

CAT_ARGS="-e --number -t -T"
assert 339

CAT_ARGS="-e --number -t -v"
assert 340

CAT_ARGS="-e --number -T -v"
assert 341

CAT_ARGS="-e -s --squeeze-blank -t"
assert 342

CAT_ARGS="-e -s --squeeze-blank -T"
assert 343

CAT_ARGS="-e -s --squeeze-blank -v"
assert 344

CAT_ARGS="-e -s -t -T"
assert 345

CAT_ARGS="-e -s -t -v"
assert 346

CAT_ARGS="-e -s -T -v"
assert 347

CAT_ARGS="-e --squeeze-blank -t -T"
assert 348

CAT_ARGS="-e --squeeze-blank -t -v"
assert 349

CAT_ARGS="-e --squeeze-blank -T -v"
assert 350

CAT_ARGS="-e -t -T -v"
assert 351

CAT_ARGS="-E -b --number-nonblank -n"
assert 352

CAT_ARGS="-E -b --number-nonblank --number"
assert 353

CAT_ARGS="-E -b --number-nonblank -s"
assert 354

CAT_ARGS="-E -b --number-nonblank --squeeze-blank"
assert 355

CAT_ARGS="-E -b --number-nonblank -t"
assert 356

CAT_ARGS="-E -b --number-nonblank -T"
assert 357

CAT_ARGS="-E -b --number-nonblank -v"
assert 358

CAT_ARGS="-E -b -n --number"
assert 359

CAT_ARGS="-E -b -n -s"
assert 360

CAT_ARGS="-E -b -n --squeeze-blank"
assert 361

CAT_ARGS="-E -b -n -t"
assert 362

CAT_ARGS="-E -b -n -T"
assert 363

CAT_ARGS="-E -b -n -v"
assert 364

CAT_ARGS="-E -b --number -s"
assert 365

CAT_ARGS="-E -b --number --squeeze-blank"
assert 366

CAT_ARGS="-E -b --number -t"
assert 367

CAT_ARGS="-E -b --number -T"
assert 368

CAT_ARGS="-E -b --number -v"
assert 369

CAT_ARGS="-E -b -s --squeeze-blank"
assert 370

CAT_ARGS="-E -b -s -t"
assert 371

CAT_ARGS="-E -b -s -T"
assert 372

CAT_ARGS="-E -b -s -v"
assert 373

CAT_ARGS="-E -b --squeeze-blank -t"
assert 374

CAT_ARGS="-E -b --squeeze-blank -T"
assert 375

CAT_ARGS="-E -b --squeeze-blank -v"
assert 376

CAT_ARGS="-E -b -t -T"
assert 377

CAT_ARGS="-E -b -t -v"
assert 378

CAT_ARGS="-E -b -T -v"
assert 379

CAT_ARGS="-E --number-nonblank -n --number"
assert 380

CAT_ARGS="-E --number-nonblank -n -s"
assert 381

CAT_ARGS="-E --number-nonblank -n --squeeze-blank"
assert 382

CAT_ARGS="-E --number-nonblank -n -t"
assert 383

CAT_ARGS="-E --number-nonblank -n -T"
assert 384

CAT_ARGS="-E --number-nonblank -n -v"
assert 385

CAT_ARGS="-E --number-nonblank --number -s"
assert 386

CAT_ARGS="-E --number-nonblank --number --squeeze-blank"
assert 387

CAT_ARGS="-E --number-nonblank --number -t"
assert 388

CAT_ARGS="-E --number-nonblank --number -T"
assert 389

CAT_ARGS="-E --number-nonblank --number -v"
assert 390

CAT_ARGS="-E --number-nonblank -s --squeeze-blank"
assert 391

CAT_ARGS="-E --number-nonblank -s -t"
assert 392

CAT_ARGS="-E --number-nonblank -s -T"
assert 393

CAT_ARGS="-E --number-nonblank -s -v"
assert 394

CAT_ARGS="-E --number-nonblank --squeeze-blank -t"
assert 395

CAT_ARGS="-E --number-nonblank --squeeze-blank -T"
assert 396

CAT_ARGS="-E --number-nonblank --squeeze-blank -v"
assert 397

CAT_ARGS="-E --number-nonblank -t -T"
assert 398

CAT_ARGS="-E --number-nonblank -t -v"
assert 399

CAT_ARGS="-E --number-nonblank -T -v"
assert 400

CAT_ARGS="-E -n --number -s"
assert 401

CAT_ARGS="-E -n --number --squeeze-blank"
assert 402

CAT_ARGS="-E -n --number -t"
assert 403

CAT_ARGS="-E -n --number -T"
assert 404

CAT_ARGS="-E -n --number -v"
assert 405

CAT_ARGS="-E -n -s --squeeze-blank"
assert 406

CAT_ARGS="-E -n -s -t"
assert 407

CAT_ARGS="-E -n -s -T"
assert 408

CAT_ARGS="-E -n -s -v"
assert 409

CAT_ARGS="-E -n --squeeze-blank -t"
assert 410

CAT_ARGS="-E -n --squeeze-blank -T"
assert 411

CAT_ARGS="-E -n --squeeze-blank -v"
assert 412

CAT_ARGS="-E -n -t -T"
assert 413

CAT_ARGS="-E -n -t -v"
assert 414

CAT_ARGS="-E -n -T -v"
assert 415

CAT_ARGS="-E --number -s --squeeze-blank"
assert 416

CAT_ARGS="-E --number -s -t"
assert 417

CAT_ARGS="-E --number -s -T"
assert 418

CAT_ARGS="-E --number -s -v"
assert 419

CAT_ARGS="-E --number --squeeze-blank -t"
assert 420

CAT_ARGS="-E --number --squeeze-blank -T"
assert 421

CAT_ARGS="-E --number --squeeze-blank -v"
assert 422

CAT_ARGS="-E --number -t -T"
assert 423

CAT_ARGS="-E --number -t -v"
assert 424

CAT_ARGS="-E --number -T -v"
assert 425

CAT_ARGS="-E -s --squeeze-blank -t"
assert 426

CAT_ARGS="-E -s --squeeze-blank -T"
assert 427

CAT_ARGS="-E -s --squeeze-blank -v"
assert 428

CAT_ARGS="-E -s -t -T"
assert 429

CAT_ARGS="-E -s -t -v"
assert 430

CAT_ARGS="-E -s -T -v"
assert 431

CAT_ARGS="-E --squeeze-blank -t -T"
assert 432

CAT_ARGS="-E --squeeze-blank -t -v"
assert 433

CAT_ARGS="-E --squeeze-blank -T -v"
assert 434

CAT_ARGS="-E -t -T -v"
assert 435

CAT_ARGS="-b --number-nonblank -n --number"
assert 436

CAT_ARGS="-b --number-nonblank -n -s"
assert 437

CAT_ARGS="-b --number-nonblank -n --squeeze-blank"
assert 438

CAT_ARGS="-b --number-nonblank -n -t"
assert 439

CAT_ARGS="-b --number-nonblank -n -T"
assert 440

CAT_ARGS="-b --number-nonblank -n -v"
assert 441

CAT_ARGS="-b --number-nonblank --number -s"
assert 442

CAT_ARGS="-b --number-nonblank --number --squeeze-blank"
assert 443

CAT_ARGS="-b --number-nonblank --number -t"
assert 444

CAT_ARGS="-b --number-nonblank --number -T"
assert 445

CAT_ARGS="-b --number-nonblank --number -v"
assert 446

CAT_ARGS="-b --number-nonblank -s --squeeze-blank"
assert 447

CAT_ARGS="-b --number-nonblank -s -t"
assert 448

CAT_ARGS="-b --number-nonblank -s -T"
assert 449

CAT_ARGS="-b --number-nonblank -s -v"
assert 450

CAT_ARGS="-b --number-nonblank --squeeze-blank -t"
assert 451

CAT_ARGS="-b --number-nonblank --squeeze-blank -T"
assert 452

CAT_ARGS="-b --number-nonblank --squeeze-blank -v"
assert 453

CAT_ARGS="-b --number-nonblank -t -T"
assert 454

CAT_ARGS="-b --number-nonblank -t -v"
assert 455

CAT_ARGS="-b --number-nonblank -T -v"
assert 456

CAT_ARGS="-b -n --number -s"
assert 457

CAT_ARGS="-b -n --number --squeeze-blank"
assert 458

CAT_ARGS="-b -n --number -t"
assert 459

CAT_ARGS="-b -n --number -T"
assert 460

CAT_ARGS="-b -n --number -v"
assert 461

CAT_ARGS="-b -n -s --squeeze-blank"
assert 462

CAT_ARGS="-b -n -s -t"
assert 463

CAT_ARGS="-b -n -s -T"
assert 464

CAT_ARGS="-b -n -s -v"
assert 465

CAT_ARGS="-b -n --squeeze-blank -t"
assert 466

CAT_ARGS="-b -n --squeeze-blank -T"
assert 467

CAT_ARGS="-b -n --squeeze-blank -v"
assert 468

CAT_ARGS="-b -n -t -T"
assert 469

CAT_ARGS="-b -n -t -v"
assert 470

CAT_ARGS="-b -n -T -v"
assert 471

CAT_ARGS="-b --number -s --squeeze-blank"
assert 472

CAT_ARGS="-b --number -s -t"
assert 473

CAT_ARGS="-b --number -s -T"
assert 474

CAT_ARGS="-b --number -s -v"
assert 475

CAT_ARGS="-b --number --squeeze-blank -t"
assert 476

CAT_ARGS="-b --number --squeeze-blank -T"
assert 477

CAT_ARGS="-b --number --squeeze-blank -v"
assert 478

CAT_ARGS="-b --number -t -T"
assert 479

CAT_ARGS="-b --number -t -v"
assert 480

CAT_ARGS="-b --number -T -v"
assert 481

CAT_ARGS="-b -s --squeeze-blank -t"
assert 482

CAT_ARGS="-b -s --squeeze-blank -T"
assert 483

CAT_ARGS="-b -s --squeeze-blank -v"
assert 484

CAT_ARGS="-b -s -t -T"
assert 485

CAT_ARGS="-b -s -t -v"
assert 486

CAT_ARGS="-b -s -T -v"
assert 487

CAT_ARGS="-b --squeeze-blank -t -T"
assert 488

CAT_ARGS="-b --squeeze-blank -t -v"
assert 489

CAT_ARGS="-b --squeeze-blank -T -v"
assert 490

CAT_ARGS="-b -t -T -v"
assert 491

CAT_ARGS="--number-nonblank -n --number -s"
assert 492

CAT_ARGS="--number-nonblank -n --number --squeeze-blank"
assert 493

CAT_ARGS="--number-nonblank -n --number -t"
assert 494

CAT_ARGS="--number-nonblank -n --number -T"
assert 495

CAT_ARGS="--number-nonblank -n --number -v"
assert 496

CAT_ARGS="--number-nonblank -n -s --squeeze-blank"
assert 497

CAT_ARGS="--number-nonblank -n -s -t"
assert 498

CAT_ARGS="--number-nonblank -n -s -T"
assert 499

CAT_ARGS="--number-nonblank -n -s -v"
assert 500

CAT_ARGS="--number-nonblank -n --squeeze-blank -t"
assert 501

CAT_ARGS="--number-nonblank -n --squeeze-blank -T"
assert 502

CAT_ARGS="--number-nonblank -n --squeeze-blank -v"
assert 503

CAT_ARGS="--number-nonblank -n -t -T"
assert 504

CAT_ARGS="--number-nonblank -n -t -v"
assert 505

CAT_ARGS="--number-nonblank -n -T -v"
assert 506

CAT_ARGS="--number-nonblank --number -s --squeeze-blank"
assert 507

CAT_ARGS="--number-nonblank --number -s -t"
assert 508

CAT_ARGS="--number-nonblank --number -s -T"
assert 509

CAT_ARGS="--number-nonblank --number -s -v"
assert 510

CAT_ARGS="--number-nonblank --number --squeeze-blank -t"
assert 511

CAT_ARGS="--number-nonblank --number --squeeze-blank -T"
assert 512

CAT_ARGS="--number-nonblank --number --squeeze-blank -v"
assert 513

CAT_ARGS="--number-nonblank --number -t -T"
assert 514

CAT_ARGS="--number-nonblank --number -t -v"
assert 515

CAT_ARGS="--number-nonblank --number -T -v"
assert 516

CAT_ARGS="--number-nonblank -s --squeeze-blank -t"
assert 517

CAT_ARGS="--number-nonblank -s --squeeze-blank -T"
assert 518

CAT_ARGS="--number-nonblank -s --squeeze-blank -v"
assert 519

CAT_ARGS="--number-nonblank -s -t -T"
assert 520

CAT_ARGS="--number-nonblank -s -t -v"
assert 521

CAT_ARGS="--number-nonblank -s -T -v"
assert 522

CAT_ARGS="--number-nonblank --squeeze-blank -t -T"
assert 523

CAT_ARGS="--number-nonblank --squeeze-blank -t -v"
assert 524

CAT_ARGS="--number-nonblank --squeeze-blank -T -v"
assert 525

CAT_ARGS="--number-nonblank -t -T -v"
assert 526

CAT_ARGS="-n --number -s --squeeze-blank"
assert 527

CAT_ARGS="-n --number -s -t"
assert 528

CAT_ARGS="-n --number -s -T"
assert 529

CAT_ARGS="-n --number -s -v"
assert 530

CAT_ARGS="-n --number --squeeze-blank -t"
assert 531

CAT_ARGS="-n --number --squeeze-blank -T"
assert 532

CAT_ARGS="-n --number --squeeze-blank -v"
assert 533

CAT_ARGS="-n --number -t -T"
assert 534

CAT_ARGS="-n --number -t -v"
assert 535

CAT_ARGS="-n --number -T -v"
assert 536

CAT_ARGS="-n -s --squeeze-blank -t"
assert 537

CAT_ARGS="-n -s --squeeze-blank -T"
assert 538

CAT_ARGS="-n -s --squeeze-blank -v"
assert 539

CAT_ARGS="-n -s -t -T"
assert 540

CAT_ARGS="-n -s -t -v"
assert 541

CAT_ARGS="-n -s -T -v"
assert 542

CAT_ARGS="-n --squeeze-blank -t -T"
assert 543

CAT_ARGS="-n --squeeze-blank -t -v"
assert 544

CAT_ARGS="-n --squeeze-blank -T -v"
assert 545

CAT_ARGS="-n -t -T -v"
assert 546

CAT_ARGS="--number -s --squeeze-blank -t"
assert 547

CAT_ARGS="--number -s --squeeze-blank -T"
assert 548

CAT_ARGS="--number -s --squeeze-blank -v"
assert 549

CAT_ARGS="--number -s -t -T"
assert 550

CAT_ARGS="--number -s -t -v"
assert 551

CAT_ARGS="--number -s -T -v"
assert 552

CAT_ARGS="--number --squeeze-blank -t -T"
assert 553

CAT_ARGS="--number --squeeze-blank -t -v"
assert 554

CAT_ARGS="--number --squeeze-blank -T -v"
assert 555

CAT_ARGS="--number -t -T -v"
assert 556

CAT_ARGS="-s --squeeze-blank -t -T"
assert 557

CAT_ARGS="-s --squeeze-blank -t -v"
assert 558

CAT_ARGS="-s --squeeze-blank -T -v"
assert 559

CAT_ARGS="-s -t -T -v"
assert 560

CAT_ARGS="--squeeze-blank -t -T -v"
assert 561

CAT_ARGS="-e -E -b --number-nonblank -n"
assert 562

CAT_ARGS="-e -E -b --number-nonblank --number"
assert 563

CAT_ARGS="-e -E -b --number-nonblank -s"
assert 564

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank"
assert 565

CAT_ARGS="-e -E -b --number-nonblank -t"
assert 566

CAT_ARGS="-e -E -b --number-nonblank -T"
assert 567

CAT_ARGS="-e -E -b --number-nonblank -v"
assert 568

CAT_ARGS="-e -E -b -n --number"
assert 569

CAT_ARGS="-e -E -b -n -s"
assert 570

CAT_ARGS="-e -E -b -n --squeeze-blank"
assert 571

CAT_ARGS="-e -E -b -n -t"
assert 572

CAT_ARGS="-e -E -b -n -T"
assert 573

CAT_ARGS="-e -E -b -n -v"
assert 574

CAT_ARGS="-e -E -b --number -s"
assert 575

CAT_ARGS="-e -E -b --number --squeeze-blank"
assert 576

CAT_ARGS="-e -E -b --number -t"
assert 577

CAT_ARGS="-e -E -b --number -T"
assert 578

CAT_ARGS="-e -E -b --number -v"
assert 579

CAT_ARGS="-e -E -b -s --squeeze-blank"
assert 580

CAT_ARGS="-e -E -b -s -t"
assert 581

CAT_ARGS="-e -E -b -s -T"
assert 582

CAT_ARGS="-e -E -b -s -v"
assert 583

CAT_ARGS="-e -E -b --squeeze-blank -t"
assert 584

CAT_ARGS="-e -E -b --squeeze-blank -T"
assert 585

CAT_ARGS="-e -E -b --squeeze-blank -v"
assert 586

CAT_ARGS="-e -E -b -t -T"
assert 587

CAT_ARGS="-e -E -b -t -v"
assert 588

CAT_ARGS="-e -E -b -T -v"
assert 589

CAT_ARGS="-e -E --number-nonblank -n --number"
assert 590

CAT_ARGS="-e -E --number-nonblank -n -s"
assert 591

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank"
assert 592

CAT_ARGS="-e -E --number-nonblank -n -t"
assert 593

CAT_ARGS="-e -E --number-nonblank -n -T"
assert 594

CAT_ARGS="-e -E --number-nonblank -n -v"
assert 595

CAT_ARGS="-e -E --number-nonblank --number -s"
assert 596

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank"
assert 597

CAT_ARGS="-e -E --number-nonblank --number -t"
assert 598

CAT_ARGS="-e -E --number-nonblank --number -T"
assert 599

CAT_ARGS="-e -E --number-nonblank --number -v"
assert 600

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank"
assert 601

CAT_ARGS="-e -E --number-nonblank -s -t"
assert 602

CAT_ARGS="-e -E --number-nonblank -s -T"
assert 603

CAT_ARGS="-e -E --number-nonblank -s -v"
assert 604

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -t"
assert 605

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -T"
assert 606

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -v"
assert 607

CAT_ARGS="-e -E --number-nonblank -t -T"
assert 608

CAT_ARGS="-e -E --number-nonblank -t -v"
assert 609

CAT_ARGS="-e -E --number-nonblank -T -v"
assert 610

CAT_ARGS="-e -E -n --number -s"
assert 611

CAT_ARGS="-e -E -n --number --squeeze-blank"
assert 612

CAT_ARGS="-e -E -n --number -t"
assert 613

CAT_ARGS="-e -E -n --number -T"
assert 614

CAT_ARGS="-e -E -n --number -v"
assert 615

CAT_ARGS="-e -E -n -s --squeeze-blank"
assert 616

CAT_ARGS="-e -E -n -s -t"
assert 617

CAT_ARGS="-e -E -n -s -T"
assert 618

CAT_ARGS="-e -E -n -s -v"
assert 619

CAT_ARGS="-e -E -n --squeeze-blank -t"
assert 620

CAT_ARGS="-e -E -n --squeeze-blank -T"
assert 621

CAT_ARGS="-e -E -n --squeeze-blank -v"
assert 622

CAT_ARGS="-e -E -n -t -T"
assert 623

CAT_ARGS="-e -E -n -t -v"
assert 624

CAT_ARGS="-e -E -n -T -v"
assert 625

CAT_ARGS="-e -E --number -s --squeeze-blank"
assert 626

CAT_ARGS="-e -E --number -s -t"
assert 627

CAT_ARGS="-e -E --number -s -T"
assert 628

CAT_ARGS="-e -E --number -s -v"
assert 629

CAT_ARGS="-e -E --number --squeeze-blank -t"
assert 630

CAT_ARGS="-e -E --number --squeeze-blank -T"
assert 631

CAT_ARGS="-e -E --number --squeeze-blank -v"
assert 632

CAT_ARGS="-e -E --number -t -T"
assert 633

CAT_ARGS="-e -E --number -t -v"
assert 634

CAT_ARGS="-e -E --number -T -v"
assert 635

CAT_ARGS="-e -E -s --squeeze-blank -t"
assert 636

CAT_ARGS="-e -E -s --squeeze-blank -T"
assert 637

CAT_ARGS="-e -E -s --squeeze-blank -v"
assert 638

CAT_ARGS="-e -E -s -t -T"
assert 639

CAT_ARGS="-e -E -s -t -v"
assert 640

CAT_ARGS="-e -E -s -T -v"
assert 641

CAT_ARGS="-e -E --squeeze-blank -t -T"
assert 642

CAT_ARGS="-e -E --squeeze-blank -t -v"
assert 643

CAT_ARGS="-e -E --squeeze-blank -T -v"
assert 644

CAT_ARGS="-e -E -t -T -v"
assert 645

CAT_ARGS="-e -b --number-nonblank -n --number"
assert 646

CAT_ARGS="-e -b --number-nonblank -n -s"
assert 647

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank"
assert 648

CAT_ARGS="-e -b --number-nonblank -n -t"
assert 649

CAT_ARGS="-e -b --number-nonblank -n -T"
assert 650

CAT_ARGS="-e -b --number-nonblank -n -v"
assert 651

CAT_ARGS="-e -b --number-nonblank --number -s"
assert 652

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank"
assert 653

CAT_ARGS="-e -b --number-nonblank --number -t"
assert 654

CAT_ARGS="-e -b --number-nonblank --number -T"
assert 655

CAT_ARGS="-e -b --number-nonblank --number -v"
assert 656

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank"
assert 657

CAT_ARGS="-e -b --number-nonblank -s -t"
assert 658

CAT_ARGS="-e -b --number-nonblank -s -T"
assert 659

CAT_ARGS="-e -b --number-nonblank -s -v"
assert 660

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -t"
assert 661

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -T"
assert 662

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -v"
assert 663

CAT_ARGS="-e -b --number-nonblank -t -T"
assert 664

CAT_ARGS="-e -b --number-nonblank -t -v"
assert 665

CAT_ARGS="-e -b --number-nonblank -T -v"
assert 666

CAT_ARGS="-e -b -n --number -s"
assert 667

CAT_ARGS="-e -b -n --number --squeeze-blank"
assert 668

CAT_ARGS="-e -b -n --number -t"
assert 669

CAT_ARGS="-e -b -n --number -T"
assert 670

CAT_ARGS="-e -b -n --number -v"
assert 671

CAT_ARGS="-e -b -n -s --squeeze-blank"
assert 672

CAT_ARGS="-e -b -n -s -t"
assert 673

CAT_ARGS="-e -b -n -s -T"
assert 674

CAT_ARGS="-e -b -n -s -v"
assert 675

CAT_ARGS="-e -b -n --squeeze-blank -t"
assert 676

CAT_ARGS="-e -b -n --squeeze-blank -T"
assert 677

CAT_ARGS="-e -b -n --squeeze-blank -v"
assert 678

CAT_ARGS="-e -b -n -t -T"
assert 679

CAT_ARGS="-e -b -n -t -v"
assert 680

CAT_ARGS="-e -b -n -T -v"
assert 681

CAT_ARGS="-e -b --number -s --squeeze-blank"
assert 682

CAT_ARGS="-e -b --number -s -t"
assert 683

CAT_ARGS="-e -b --number -s -T"
assert 684

CAT_ARGS="-e -b --number -s -v"
assert 685

CAT_ARGS="-e -b --number --squeeze-blank -t"
assert 686

CAT_ARGS="-e -b --number --squeeze-blank -T"
assert 687

CAT_ARGS="-e -b --number --squeeze-blank -v"
assert 688

CAT_ARGS="-e -b --number -t -T"
assert 689

CAT_ARGS="-e -b --number -t -v"
assert 690

CAT_ARGS="-e -b --number -T -v"
assert 691

CAT_ARGS="-e -b -s --squeeze-blank -t"
assert 692

CAT_ARGS="-e -b -s --squeeze-blank -T"
assert 693

CAT_ARGS="-e -b -s --squeeze-blank -v"
assert 694

CAT_ARGS="-e -b -s -t -T"
assert 695

CAT_ARGS="-e -b -s -t -v"
assert 696

CAT_ARGS="-e -b -s -T -v"
assert 697

CAT_ARGS="-e -b --squeeze-blank -t -T"
assert 698

CAT_ARGS="-e -b --squeeze-blank -t -v"
assert 699

CAT_ARGS="-e -b --squeeze-blank -T -v"
assert 700

CAT_ARGS="-e -b -t -T -v"
assert 701

CAT_ARGS="-e --number-nonblank -n --number -s"
assert 702

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank"
assert 703

CAT_ARGS="-e --number-nonblank -n --number -t"
assert 704

CAT_ARGS="-e --number-nonblank -n --number -T"
assert 705

CAT_ARGS="-e --number-nonblank -n --number -v"
assert 706

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank"
assert 707

CAT_ARGS="-e --number-nonblank -n -s -t"
assert 708

CAT_ARGS="-e --number-nonblank -n -s -T"
assert 709

CAT_ARGS="-e --number-nonblank -n -s -v"
assert 710

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -t"
assert 711

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -T"
assert 712

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -v"
assert 713

CAT_ARGS="-e --number-nonblank -n -t -T"
assert 714

CAT_ARGS="-e --number-nonblank -n -t -v"
assert 715

CAT_ARGS="-e --number-nonblank -n -T -v"
assert 716

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank"
assert 717

CAT_ARGS="-e --number-nonblank --number -s -t"
assert 718

CAT_ARGS="-e --number-nonblank --number -s -T"
assert 719

CAT_ARGS="-e --number-nonblank --number -s -v"
assert 720

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -t"
assert 721

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -T"
assert 722

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -v"
assert 723

CAT_ARGS="-e --number-nonblank --number -t -T"
assert 724

CAT_ARGS="-e --number-nonblank --number -t -v"
assert 725

CAT_ARGS="-e --number-nonblank --number -T -v"
assert 726

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -t"
assert 727

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -T"
assert 728

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -v"
assert 729

CAT_ARGS="-e --number-nonblank -s -t -T"
assert 730

CAT_ARGS="-e --number-nonblank -s -t -v"
assert 731

CAT_ARGS="-e --number-nonblank -s -T -v"
assert 732

CAT_ARGS="-e --number-nonblank --squeeze-blank -t -T"
assert 733

CAT_ARGS="-e --number-nonblank --squeeze-blank -t -v"
assert 734

CAT_ARGS="-e --number-nonblank --squeeze-blank -T -v"
assert 735

CAT_ARGS="-e --number-nonblank -t -T -v"
assert 736

CAT_ARGS="-e -n --number -s --squeeze-blank"
assert 737

CAT_ARGS="-e -n --number -s -t"
assert 738

CAT_ARGS="-e -n --number -s -T"
assert 739

CAT_ARGS="-e -n --number -s -v"
assert 740

CAT_ARGS="-e -n --number --squeeze-blank -t"
assert 741

CAT_ARGS="-e -n --number --squeeze-blank -T"
assert 742

CAT_ARGS="-e -n --number --squeeze-blank -v"
assert 743

CAT_ARGS="-e -n --number -t -T"
assert 744

CAT_ARGS="-e -n --number -t -v"
assert 745

CAT_ARGS="-e -n --number -T -v"
assert 746

CAT_ARGS="-e -n -s --squeeze-blank -t"
assert 747

CAT_ARGS="-e -n -s --squeeze-blank -T"
assert 748

CAT_ARGS="-e -n -s --squeeze-blank -v"
assert 749

CAT_ARGS="-e -n -s -t -T"
assert 750

CAT_ARGS="-e -n -s -t -v"
assert 751

CAT_ARGS="-e -n -s -T -v"
assert 752

CAT_ARGS="-e -n --squeeze-blank -t -T"
assert 753

CAT_ARGS="-e -n --squeeze-blank -t -v"
assert 754

CAT_ARGS="-e -n --squeeze-blank -T -v"
assert 755

CAT_ARGS="-e -n -t -T -v"
assert 756

CAT_ARGS="-e --number -s --squeeze-blank -t"
assert 757

CAT_ARGS="-e --number -s --squeeze-blank -T"
assert 758

CAT_ARGS="-e --number -s --squeeze-blank -v"
assert 759

CAT_ARGS="-e --number -s -t -T"
assert 760

CAT_ARGS="-e --number -s -t -v"
assert 761

CAT_ARGS="-e --number -s -T -v"
assert 762

CAT_ARGS="-e --number --squeeze-blank -t -T"
assert 763

CAT_ARGS="-e --number --squeeze-blank -t -v"
assert 764

CAT_ARGS="-e --number --squeeze-blank -T -v"
assert 765

CAT_ARGS="-e --number -t -T -v"
assert 766

CAT_ARGS="-e -s --squeeze-blank -t -T"
assert 767

CAT_ARGS="-e -s --squeeze-blank -t -v"
assert 768

CAT_ARGS="-e -s --squeeze-blank -T -v"
assert 769

CAT_ARGS="-e -s -t -T -v"
assert 770

CAT_ARGS="-e --squeeze-blank -t -T -v"
assert 771

CAT_ARGS="-E -b --number-nonblank -n --number"
assert 772

CAT_ARGS="-E -b --number-nonblank -n -s"
assert 773

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank"
assert 774

CAT_ARGS="-E -b --number-nonblank -n -t"
assert 775

CAT_ARGS="-E -b --number-nonblank -n -T"
assert 776

CAT_ARGS="-E -b --number-nonblank -n -v"
assert 777

CAT_ARGS="-E -b --number-nonblank --number -s"
assert 778

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank"
assert 779

CAT_ARGS="-E -b --number-nonblank --number -t"
assert 780

CAT_ARGS="-E -b --number-nonblank --number -T"
assert 781

CAT_ARGS="-E -b --number-nonblank --number -v"
assert 782

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank"
assert 783

CAT_ARGS="-E -b --number-nonblank -s -t"
assert 784

CAT_ARGS="-E -b --number-nonblank -s -T"
assert 785

CAT_ARGS="-E -b --number-nonblank -s -v"
assert 786

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -t"
assert 787

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -T"
assert 788

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -v"
assert 789

CAT_ARGS="-E -b --number-nonblank -t -T"
assert 790

CAT_ARGS="-E -b --number-nonblank -t -v"
assert 791

CAT_ARGS="-E -b --number-nonblank -T -v"
assert 792

CAT_ARGS="-E -b -n --number -s"
assert 793

CAT_ARGS="-E -b -n --number --squeeze-blank"
assert 794

CAT_ARGS="-E -b -n --number -t"
assert 795

CAT_ARGS="-E -b -n --number -T"
assert 796

CAT_ARGS="-E -b -n --number -v"
assert 797

CAT_ARGS="-E -b -n -s --squeeze-blank"
assert 798

CAT_ARGS="-E -b -n -s -t"
assert 799

CAT_ARGS="-E -b -n -s -T"
assert 800

CAT_ARGS="-E -b -n -s -v"
assert 801

CAT_ARGS="-E -b -n --squeeze-blank -t"
assert 802

CAT_ARGS="-E -b -n --squeeze-blank -T"
assert 803

CAT_ARGS="-E -b -n --squeeze-blank -v"
assert 804

CAT_ARGS="-E -b -n -t -T"
assert 805

CAT_ARGS="-E -b -n -t -v"
assert 806

CAT_ARGS="-E -b -n -T -v"
assert 807

CAT_ARGS="-E -b --number -s --squeeze-blank"
assert 808

CAT_ARGS="-E -b --number -s -t"
assert 809

CAT_ARGS="-E -b --number -s -T"
assert 810

CAT_ARGS="-E -b --number -s -v"
assert 811

CAT_ARGS="-E -b --number --squeeze-blank -t"
assert 812

CAT_ARGS="-E -b --number --squeeze-blank -T"
assert 813

CAT_ARGS="-E -b --number --squeeze-blank -v"
assert 814

CAT_ARGS="-E -b --number -t -T"
assert 815

CAT_ARGS="-E -b --number -t -v"
assert 816

CAT_ARGS="-E -b --number -T -v"
assert 817

CAT_ARGS="-E -b -s --squeeze-blank -t"
assert 818

CAT_ARGS="-E -b -s --squeeze-blank -T"
assert 819

CAT_ARGS="-E -b -s --squeeze-blank -v"
assert 820

CAT_ARGS="-E -b -s -t -T"
assert 821

CAT_ARGS="-E -b -s -t -v"
assert 822

CAT_ARGS="-E -b -s -T -v"
assert 823

CAT_ARGS="-E -b --squeeze-blank -t -T"
assert 824

CAT_ARGS="-E -b --squeeze-blank -t -v"
assert 825

CAT_ARGS="-E -b --squeeze-blank -T -v"
assert 826

CAT_ARGS="-E -b -t -T -v"
assert 827

CAT_ARGS="-E --number-nonblank -n --number -s"
assert 828

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank"
assert 829

CAT_ARGS="-E --number-nonblank -n --number -t"
assert 830

CAT_ARGS="-E --number-nonblank -n --number -T"
assert 831

CAT_ARGS="-E --number-nonblank -n --number -v"
assert 832

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank"
assert 833

CAT_ARGS="-E --number-nonblank -n -s -t"
assert 834

CAT_ARGS="-E --number-nonblank -n -s -T"
assert 835

CAT_ARGS="-E --number-nonblank -n -s -v"
assert 836

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -t"
assert 837

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -T"
assert 838

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -v"
assert 839

CAT_ARGS="-E --number-nonblank -n -t -T"
assert 840

CAT_ARGS="-E --number-nonblank -n -t -v"
assert 841

CAT_ARGS="-E --number-nonblank -n -T -v"
assert 842

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank"
assert 843

CAT_ARGS="-E --number-nonblank --number -s -t"
assert 844

CAT_ARGS="-E --number-nonblank --number -s -T"
assert 845

CAT_ARGS="-E --number-nonblank --number -s -v"
assert 846

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -t"
assert 847

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -T"
assert 848

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -v"
assert 849

CAT_ARGS="-E --number-nonblank --number -t -T"
assert 850

CAT_ARGS="-E --number-nonblank --number -t -v"
assert 851

CAT_ARGS="-E --number-nonblank --number -T -v"
assert 852

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -t"
assert 853

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -T"
assert 854

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -v"
assert 855

CAT_ARGS="-E --number-nonblank -s -t -T"
assert 856

CAT_ARGS="-E --number-nonblank -s -t -v"
assert 857

CAT_ARGS="-E --number-nonblank -s -T -v"
assert 858

CAT_ARGS="-E --number-nonblank --squeeze-blank -t -T"
assert 859

CAT_ARGS="-E --number-nonblank --squeeze-blank -t -v"
assert 860

CAT_ARGS="-E --number-nonblank --squeeze-blank -T -v"
assert 861

CAT_ARGS="-E --number-nonblank -t -T -v"
assert 862

CAT_ARGS="-E -n --number -s --squeeze-blank"
assert 863

CAT_ARGS="-E -n --number -s -t"
assert 864

CAT_ARGS="-E -n --number -s -T"
assert 865

CAT_ARGS="-E -n --number -s -v"
assert 866

CAT_ARGS="-E -n --number --squeeze-blank -t"
assert 867

CAT_ARGS="-E -n --number --squeeze-blank -T"
assert 868

CAT_ARGS="-E -n --number --squeeze-blank -v"
assert 869

CAT_ARGS="-E -n --number -t -T"
assert 870

CAT_ARGS="-E -n --number -t -v"
assert 871

CAT_ARGS="-E -n --number -T -v"
assert 872

CAT_ARGS="-E -n -s --squeeze-blank -t"
assert 873

CAT_ARGS="-E -n -s --squeeze-blank -T"
assert 874

CAT_ARGS="-E -n -s --squeeze-blank -v"
assert 875

CAT_ARGS="-E -n -s -t -T"
assert 876

CAT_ARGS="-E -n -s -t -v"
assert 877

CAT_ARGS="-E -n -s -T -v"
assert 878

CAT_ARGS="-E -n --squeeze-blank -t -T"
assert 879

CAT_ARGS="-E -n --squeeze-blank -t -v"
assert 880

CAT_ARGS="-E -n --squeeze-blank -T -v"
assert 881

CAT_ARGS="-E -n -t -T -v"
assert 882

CAT_ARGS="-E --number -s --squeeze-blank -t"
assert 883

CAT_ARGS="-E --number -s --squeeze-blank -T"
assert 884

CAT_ARGS="-E --number -s --squeeze-blank -v"
assert 885

CAT_ARGS="-E --number -s -t -T"
assert 886

CAT_ARGS="-E --number -s -t -v"
assert 887

CAT_ARGS="-E --number -s -T -v"
assert 888

CAT_ARGS="-E --number --squeeze-blank -t -T"
assert 889

CAT_ARGS="-E --number --squeeze-blank -t -v"
assert 890

CAT_ARGS="-E --number --squeeze-blank -T -v"
assert 891

CAT_ARGS="-E --number -t -T -v"
assert 892

CAT_ARGS="-E -s --squeeze-blank -t -T"
assert 893

CAT_ARGS="-E -s --squeeze-blank -t -v"
assert 894

CAT_ARGS="-E -s --squeeze-blank -T -v"
assert 895

CAT_ARGS="-E -s -t -T -v"
assert 896

CAT_ARGS="-E --squeeze-blank -t -T -v"
assert 897

CAT_ARGS="-b --number-nonblank -n --number -s"
assert 898

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank"
assert 899

CAT_ARGS="-b --number-nonblank -n --number -t"
assert 900

CAT_ARGS="-b --number-nonblank -n --number -T"
assert 901

CAT_ARGS="-b --number-nonblank -n --number -v"
assert 902

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank"
assert 903

CAT_ARGS="-b --number-nonblank -n -s -t"
assert 904

CAT_ARGS="-b --number-nonblank -n -s -T"
assert 905

CAT_ARGS="-b --number-nonblank -n -s -v"
assert 906

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -t"
assert 907

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -T"
assert 908

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -v"
assert 909

CAT_ARGS="-b --number-nonblank -n -t -T"
assert 910

CAT_ARGS="-b --number-nonblank -n -t -v"
assert 911

CAT_ARGS="-b --number-nonblank -n -T -v"
assert 912

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank"
assert 913

CAT_ARGS="-b --number-nonblank --number -s -t"
assert 914

CAT_ARGS="-b --number-nonblank --number -s -T"
assert 915

CAT_ARGS="-b --number-nonblank --number -s -v"
assert 916

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -t"
assert 917

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -T"
assert 918

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -v"
assert 919

CAT_ARGS="-b --number-nonblank --number -t -T"
assert 920

CAT_ARGS="-b --number-nonblank --number -t -v"
assert 921

CAT_ARGS="-b --number-nonblank --number -T -v"
assert 922

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -t"
assert 923

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -T"
assert 924

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -v"
assert 925

CAT_ARGS="-b --number-nonblank -s -t -T"
assert 926

CAT_ARGS="-b --number-nonblank -s -t -v"
assert 927

CAT_ARGS="-b --number-nonblank -s -T -v"
assert 928

CAT_ARGS="-b --number-nonblank --squeeze-blank -t -T"
assert 929

CAT_ARGS="-b --number-nonblank --squeeze-blank -t -v"
assert 930

CAT_ARGS="-b --number-nonblank --squeeze-blank -T -v"
assert 931

CAT_ARGS="-b --number-nonblank -t -T -v"
assert 932

CAT_ARGS="-b -n --number -s --squeeze-blank"
assert 933

CAT_ARGS="-b -n --number -s -t"
assert 934

CAT_ARGS="-b -n --number -s -T"
assert 935

CAT_ARGS="-b -n --number -s -v"
assert 936

CAT_ARGS="-b -n --number --squeeze-blank -t"
assert 937

CAT_ARGS="-b -n --number --squeeze-blank -T"
assert 938

CAT_ARGS="-b -n --number --squeeze-blank -v"
assert 939

CAT_ARGS="-b -n --number -t -T"
assert 940

CAT_ARGS="-b -n --number -t -v"
assert 941

CAT_ARGS="-b -n --number -T -v"
assert 942

CAT_ARGS="-b -n -s --squeeze-blank -t"
assert 943

CAT_ARGS="-b -n -s --squeeze-blank -T"
assert 944

CAT_ARGS="-b -n -s --squeeze-blank -v"
assert 945

CAT_ARGS="-b -n -s -t -T"
assert 946

CAT_ARGS="-b -n -s -t -v"
assert 947

CAT_ARGS="-b -n -s -T -v"
assert 948

CAT_ARGS="-b -n --squeeze-blank -t -T"
assert 949

CAT_ARGS="-b -n --squeeze-blank -t -v"
assert 950

CAT_ARGS="-b -n --squeeze-blank -T -v"
assert 951

CAT_ARGS="-b -n -t -T -v"
assert 952

CAT_ARGS="-b --number -s --squeeze-blank -t"
assert 953

CAT_ARGS="-b --number -s --squeeze-blank -T"
assert 954

CAT_ARGS="-b --number -s --squeeze-blank -v"
assert 955

CAT_ARGS="-b --number -s -t -T"
assert 956

CAT_ARGS="-b --number -s -t -v"
assert 957

CAT_ARGS="-b --number -s -T -v"
assert 958

CAT_ARGS="-b --number --squeeze-blank -t -T"
assert 959

CAT_ARGS="-b --number --squeeze-blank -t -v"
assert 960

CAT_ARGS="-b --number --squeeze-blank -T -v"
assert 961

CAT_ARGS="-b --number -t -T -v"
assert 962

CAT_ARGS="-b -s --squeeze-blank -t -T"
assert 963

CAT_ARGS="-b -s --squeeze-blank -t -v"
assert 964

CAT_ARGS="-b -s --squeeze-blank -T -v"
assert 965

CAT_ARGS="-b -s -t -T -v"
assert 966

CAT_ARGS="-b --squeeze-blank -t -T -v"
assert 967

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank"
assert 968

CAT_ARGS="--number-nonblank -n --number -s -t"
assert 969

CAT_ARGS="--number-nonblank -n --number -s -T"
assert 970

CAT_ARGS="--number-nonblank -n --number -s -v"
assert 971

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -t"
assert 972

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -T"
assert 973

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -v"
assert 974

CAT_ARGS="--number-nonblank -n --number -t -T"
assert 975

CAT_ARGS="--number-nonblank -n --number -t -v"
assert 976

CAT_ARGS="--number-nonblank -n --number -T -v"
assert 977

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -t"
assert 978

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -T"
assert 979

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -v"
assert 980

CAT_ARGS="--number-nonblank -n -s -t -T"
assert 981

CAT_ARGS="--number-nonblank -n -s -t -v"
assert 982

CAT_ARGS="--number-nonblank -n -s -T -v"
assert 983

CAT_ARGS="--number-nonblank -n --squeeze-blank -t -T"
assert 984

CAT_ARGS="--number-nonblank -n --squeeze-blank -t -v"
assert 985

CAT_ARGS="--number-nonblank -n --squeeze-blank -T -v"
assert 986

CAT_ARGS="--number-nonblank -n -t -T -v"
assert 987

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -t"
assert 988

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -T"
assert 989

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -v"
assert 990

CAT_ARGS="--number-nonblank --number -s -t -T"
assert 991

CAT_ARGS="--number-nonblank --number -s -t -v"
assert 992

CAT_ARGS="--number-nonblank --number -s -T -v"
assert 993

CAT_ARGS="--number-nonblank --number --squeeze-blank -t -T"
assert 994

CAT_ARGS="--number-nonblank --number --squeeze-blank -t -v"
assert 995

CAT_ARGS="--number-nonblank --number --squeeze-blank -T -v"
assert 996

CAT_ARGS="--number-nonblank --number -t -T -v"
assert 997

CAT_ARGS="--number-nonblank -s --squeeze-blank -t -T"
assert 998

CAT_ARGS="--number-nonblank -s --squeeze-blank -t -v"
assert 999

CAT_ARGS="--number-nonblank -s --squeeze-blank -T -v"
assert 1000

CAT_ARGS="--number-nonblank -s -t -T -v"
assert 1001

CAT_ARGS="--number-nonblank --squeeze-blank -t -T -v"
assert 1002

CAT_ARGS="-n --number -s --squeeze-blank -t"
assert 1003

CAT_ARGS="-n --number -s --squeeze-blank -T"
assert 1004

CAT_ARGS="-n --number -s --squeeze-blank -v"
assert 1005

CAT_ARGS="-n --number -s -t -T"
assert 1006

CAT_ARGS="-n --number -s -t -v"
assert 1007

CAT_ARGS="-n --number -s -T -v"
assert 1008

CAT_ARGS="-n --number --squeeze-blank -t -T"
assert 1009

CAT_ARGS="-n --number --squeeze-blank -t -v"
assert 1010

CAT_ARGS="-n --number --squeeze-blank -T -v"
assert 1011

CAT_ARGS="-n --number -t -T -v"
assert 1012

CAT_ARGS="-n -s --squeeze-blank -t -T"
assert 1013

CAT_ARGS="-n -s --squeeze-blank -t -v"
assert 1014

CAT_ARGS="-n -s --squeeze-blank -T -v"
assert 1015

CAT_ARGS="-n -s -t -T -v"
assert 1016

CAT_ARGS="-n --squeeze-blank -t -T -v"
assert 1017

CAT_ARGS="--number -s --squeeze-blank -t -T"
assert 1018

CAT_ARGS="--number -s --squeeze-blank -t -v"
assert 1019

CAT_ARGS="--number -s --squeeze-blank -T -v"
assert 1020

CAT_ARGS="--number -s -t -T -v"
assert 1021

CAT_ARGS="--number --squeeze-blank -t -T -v"
assert 1022

CAT_ARGS="-s --squeeze-blank -t -T -v"
assert 1023

CAT_ARGS="-e -E -b --number-nonblank -n --number"
assert 1024

CAT_ARGS="-e -E -b --number-nonblank -n -s"
assert 1025

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank"
assert 1026

CAT_ARGS="-e -E -b --number-nonblank -n -t"
assert 1027

CAT_ARGS="-e -E -b --number-nonblank -n -T"
assert 1028

CAT_ARGS="-e -E -b --number-nonblank -n -v"
assert 1029

CAT_ARGS="-e -E -b --number-nonblank --number -s"
assert 1030

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank"
assert 1031

CAT_ARGS="-e -E -b --number-nonblank --number -t"
assert 1032

CAT_ARGS="-e -E -b --number-nonblank --number -T"
assert 1033

CAT_ARGS="-e -E -b --number-nonblank --number -v"
assert 1034

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank"
assert 1035

CAT_ARGS="-e -E -b --number-nonblank -s -t"
assert 1036

CAT_ARGS="-e -E -b --number-nonblank -s -T"
assert 1037

CAT_ARGS="-e -E -b --number-nonblank -s -v"
assert 1038

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -t"
assert 1039

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -T"
assert 1040

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -v"
assert 1041

CAT_ARGS="-e -E -b --number-nonblank -t -T"
assert 1042

CAT_ARGS="-e -E -b --number-nonblank -t -v"
assert 1043

CAT_ARGS="-e -E -b --number-nonblank -T -v"
assert 1044

CAT_ARGS="-e -E -b -n --number -s"
assert 1045

CAT_ARGS="-e -E -b -n --number --squeeze-blank"
assert 1046

CAT_ARGS="-e -E -b -n --number -t"
assert 1047

CAT_ARGS="-e -E -b -n --number -T"
assert 1048

CAT_ARGS="-e -E -b -n --number -v"
assert 1049

CAT_ARGS="-e -E -b -n -s --squeeze-blank"
assert 1050

CAT_ARGS="-e -E -b -n -s -t"
assert 1051

CAT_ARGS="-e -E -b -n -s -T"
assert 1052

CAT_ARGS="-e -E -b -n -s -v"
assert 1053

CAT_ARGS="-e -E -b -n --squeeze-blank -t"
assert 1054

CAT_ARGS="-e -E -b -n --squeeze-blank -T"
assert 1055

CAT_ARGS="-e -E -b -n --squeeze-blank -v"
assert 1056

CAT_ARGS="-e -E -b -n -t -T"
assert 1057

CAT_ARGS="-e -E -b -n -t -v"
assert 1058

CAT_ARGS="-e -E -b -n -T -v"
assert 1059

CAT_ARGS="-e -E -b --number -s --squeeze-blank"
assert 1060

CAT_ARGS="-e -E -b --number -s -t"
assert 1061

CAT_ARGS="-e -E -b --number -s -T"
assert 1062

CAT_ARGS="-e -E -b --number -s -v"
assert 1063

CAT_ARGS="-e -E -b --number --squeeze-blank -t"
assert 1064

CAT_ARGS="-e -E -b --number --squeeze-blank -T"
assert 1065

CAT_ARGS="-e -E -b --number --squeeze-blank -v"
assert 1066

CAT_ARGS="-e -E -b --number -t -T"
assert 1067

CAT_ARGS="-e -E -b --number -t -v"
assert 1068

CAT_ARGS="-e -E -b --number -T -v"
assert 1069

CAT_ARGS="-e -E -b -s --squeeze-blank -t"
assert 1070

CAT_ARGS="-e -E -b -s --squeeze-blank -T"
assert 1071

CAT_ARGS="-e -E -b -s --squeeze-blank -v"
assert 1072

CAT_ARGS="-e -E -b -s -t -T"
assert 1073

CAT_ARGS="-e -E -b -s -t -v"
assert 1074

CAT_ARGS="-e -E -b -s -T -v"
assert 1075

CAT_ARGS="-e -E -b --squeeze-blank -t -T"
assert 1076

CAT_ARGS="-e -E -b --squeeze-blank -t -v"
assert 1077

CAT_ARGS="-e -E -b --squeeze-blank -T -v"
assert 1078

CAT_ARGS="-e -E -b -t -T -v"
assert 1079

CAT_ARGS="-e -E --number-nonblank -n --number -s"
assert 1080

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank"
assert 1081

CAT_ARGS="-e -E --number-nonblank -n --number -t"
assert 1082

CAT_ARGS="-e -E --number-nonblank -n --number -T"
assert 1083

CAT_ARGS="-e -E --number-nonblank -n --number -v"
assert 1084

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank"
assert 1085

CAT_ARGS="-e -E --number-nonblank -n -s -t"
assert 1086

CAT_ARGS="-e -E --number-nonblank -n -s -T"
assert 1087

CAT_ARGS="-e -E --number-nonblank -n -s -v"
assert 1088

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -t"
assert 1089

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -T"
assert 1090

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -v"
assert 1091

CAT_ARGS="-e -E --number-nonblank -n -t -T"
assert 1092

CAT_ARGS="-e -E --number-nonblank -n -t -v"
assert 1093

CAT_ARGS="-e -E --number-nonblank -n -T -v"
assert 1094

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank"
assert 1095

CAT_ARGS="-e -E --number-nonblank --number -s -t"
assert 1096

CAT_ARGS="-e -E --number-nonblank --number -s -T"
assert 1097

CAT_ARGS="-e -E --number-nonblank --number -s -v"
assert 1098

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -t"
assert 1099

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -T"
assert 1100

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -v"
assert 1101

CAT_ARGS="-e -E --number-nonblank --number -t -T"
assert 1102

CAT_ARGS="-e -E --number-nonblank --number -t -v"
assert 1103

CAT_ARGS="-e -E --number-nonblank --number -T -v"
assert 1104

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -t"
assert 1105

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -T"
assert 1106

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -v"
assert 1107

CAT_ARGS="-e -E --number-nonblank -s -t -T"
assert 1108

CAT_ARGS="-e -E --number-nonblank -s -t -v"
assert 1109

CAT_ARGS="-e -E --number-nonblank -s -T -v"
assert 1110

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -t -T"
assert 1111

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -t -v"
assert 1112

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -T -v"
assert 1113

CAT_ARGS="-e -E --number-nonblank -t -T -v"
assert 1114

CAT_ARGS="-e -E -n --number -s --squeeze-blank"
assert 1115

CAT_ARGS="-e -E -n --number -s -t"
assert 1116

CAT_ARGS="-e -E -n --number -s -T"
assert 1117

CAT_ARGS="-e -E -n --number -s -v"
assert 1118

CAT_ARGS="-e -E -n --number --squeeze-blank -t"
assert 1119

CAT_ARGS="-e -E -n --number --squeeze-blank -T"
assert 1120

CAT_ARGS="-e -E -n --number --squeeze-blank -v"
assert 1121

CAT_ARGS="-e -E -n --number -t -T"
assert 1122

CAT_ARGS="-e -E -n --number -t -v"
assert 1123

CAT_ARGS="-e -E -n --number -T -v"
assert 1124

CAT_ARGS="-e -E -n -s --squeeze-blank -t"
assert 1125

CAT_ARGS="-e -E -n -s --squeeze-blank -T"
assert 1126

CAT_ARGS="-e -E -n -s --squeeze-blank -v"
assert 1127

CAT_ARGS="-e -E -n -s -t -T"
assert 1128

CAT_ARGS="-e -E -n -s -t -v"
assert 1129

CAT_ARGS="-e -E -n -s -T -v"
assert 1130

CAT_ARGS="-e -E -n --squeeze-blank -t -T"
assert 1131

CAT_ARGS="-e -E -n --squeeze-blank -t -v"
assert 1132

CAT_ARGS="-e -E -n --squeeze-blank -T -v"
assert 1133

CAT_ARGS="-e -E -n -t -T -v"
assert 1134

CAT_ARGS="-e -E --number -s --squeeze-blank -t"
assert 1135

CAT_ARGS="-e -E --number -s --squeeze-blank -T"
assert 1136

CAT_ARGS="-e -E --number -s --squeeze-blank -v"
assert 1137

CAT_ARGS="-e -E --number -s -t -T"
assert 1138

CAT_ARGS="-e -E --number -s -t -v"
assert 1139

CAT_ARGS="-e -E --number -s -T -v"
assert 1140

CAT_ARGS="-e -E --number --squeeze-blank -t -T"
assert 1141

CAT_ARGS="-e -E --number --squeeze-blank -t -v"
assert 1142

CAT_ARGS="-e -E --number --squeeze-blank -T -v"
assert 1143

CAT_ARGS="-e -E --number -t -T -v"
assert 1144

CAT_ARGS="-e -E -s --squeeze-blank -t -T"
assert 1145

CAT_ARGS="-e -E -s --squeeze-blank -t -v"
assert 1146

CAT_ARGS="-e -E -s --squeeze-blank -T -v"
assert 1147

CAT_ARGS="-e -E -s -t -T -v"
assert 1148

CAT_ARGS="-e -E --squeeze-blank -t -T -v"
assert 1149

CAT_ARGS="-e -b --number-nonblank -n --number -s"
assert 1150

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank"
assert 1151

CAT_ARGS="-e -b --number-nonblank -n --number -t"
assert 1152

CAT_ARGS="-e -b --number-nonblank -n --number -T"
assert 1153

CAT_ARGS="-e -b --number-nonblank -n --number -v"
assert 1154

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank"
assert 1155

CAT_ARGS="-e -b --number-nonblank -n -s -t"
assert 1156

CAT_ARGS="-e -b --number-nonblank -n -s -T"
assert 1157

CAT_ARGS="-e -b --number-nonblank -n -s -v"
assert 1158

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -t"
assert 1159

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -T"
assert 1160

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -v"
assert 1161

CAT_ARGS="-e -b --number-nonblank -n -t -T"
assert 1162

CAT_ARGS="-e -b --number-nonblank -n -t -v"
assert 1163

CAT_ARGS="-e -b --number-nonblank -n -T -v"
assert 1164

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank"
assert 1165

CAT_ARGS="-e -b --number-nonblank --number -s -t"
assert 1166

CAT_ARGS="-e -b --number-nonblank --number -s -T"
assert 1167

CAT_ARGS="-e -b --number-nonblank --number -s -v"
assert 1168

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -t"
assert 1169

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -T"
assert 1170

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -v"
assert 1171

CAT_ARGS="-e -b --number-nonblank --number -t -T"
assert 1172

CAT_ARGS="-e -b --number-nonblank --number -t -v"
assert 1173

CAT_ARGS="-e -b --number-nonblank --number -T -v"
assert 1174

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -t"
assert 1175

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -T"
assert 1176

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -v"
assert 1177

CAT_ARGS="-e -b --number-nonblank -s -t -T"
assert 1178

CAT_ARGS="-e -b --number-nonblank -s -t -v"
assert 1179

CAT_ARGS="-e -b --number-nonblank -s -T -v"
assert 1180

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -t -T"
assert 1181

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -t -v"
assert 1182

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -T -v"
assert 1183

CAT_ARGS="-e -b --number-nonblank -t -T -v"
assert 1184

CAT_ARGS="-e -b -n --number -s --squeeze-blank"
assert 1185

CAT_ARGS="-e -b -n --number -s -t"
assert 1186

CAT_ARGS="-e -b -n --number -s -T"
assert 1187

CAT_ARGS="-e -b -n --number -s -v"
assert 1188

CAT_ARGS="-e -b -n --number --squeeze-blank -t"
assert 1189

CAT_ARGS="-e -b -n --number --squeeze-blank -T"
assert 1190

CAT_ARGS="-e -b -n --number --squeeze-blank -v"
assert 1191

CAT_ARGS="-e -b -n --number -t -T"
assert 1192

CAT_ARGS="-e -b -n --number -t -v"
assert 1193

CAT_ARGS="-e -b -n --number -T -v"
assert 1194

CAT_ARGS="-e -b -n -s --squeeze-blank -t"
assert 1195

CAT_ARGS="-e -b -n -s --squeeze-blank -T"
assert 1196

CAT_ARGS="-e -b -n -s --squeeze-blank -v"
assert 1197

CAT_ARGS="-e -b -n -s -t -T"
assert 1198

CAT_ARGS="-e -b -n -s -t -v"
assert 1199

CAT_ARGS="-e -b -n -s -T -v"
assert 1200

CAT_ARGS="-e -b -n --squeeze-blank -t -T"
assert 1201

CAT_ARGS="-e -b -n --squeeze-blank -t -v"
assert 1202

CAT_ARGS="-e -b -n --squeeze-blank -T -v"
assert 1203

CAT_ARGS="-e -b -n -t -T -v"
assert 1204

CAT_ARGS="-e -b --number -s --squeeze-blank -t"
assert 1205

CAT_ARGS="-e -b --number -s --squeeze-blank -T"
assert 1206

CAT_ARGS="-e -b --number -s --squeeze-blank -v"
assert 1207

CAT_ARGS="-e -b --number -s -t -T"
assert 1208

CAT_ARGS="-e -b --number -s -t -v"
assert 1209

CAT_ARGS="-e -b --number -s -T -v"
assert 1210

CAT_ARGS="-e -b --number --squeeze-blank -t -T"
assert 1211

CAT_ARGS="-e -b --number --squeeze-blank -t -v"
assert 1212

CAT_ARGS="-e -b --number --squeeze-blank -T -v"
assert 1213

CAT_ARGS="-e -b --number -t -T -v"
assert 1214

CAT_ARGS="-e -b -s --squeeze-blank -t -T"
assert 1215

CAT_ARGS="-e -b -s --squeeze-blank -t -v"
assert 1216

CAT_ARGS="-e -b -s --squeeze-blank -T -v"
assert 1217

CAT_ARGS="-e -b -s -t -T -v"
assert 1218

CAT_ARGS="-e -b --squeeze-blank -t -T -v"
assert 1219

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank"
assert 1220

CAT_ARGS="-e --number-nonblank -n --number -s -t"
assert 1221

CAT_ARGS="-e --number-nonblank -n --number -s -T"
assert 1222

CAT_ARGS="-e --number-nonblank -n --number -s -v"
assert 1223

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -t"
assert 1224

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -T"
assert 1225

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -v"
assert 1226

CAT_ARGS="-e --number-nonblank -n --number -t -T"
assert 1227

CAT_ARGS="-e --number-nonblank -n --number -t -v"
assert 1228

CAT_ARGS="-e --number-nonblank -n --number -T -v"
assert 1229

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -t"
assert 1230

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -T"
assert 1231

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -v"
assert 1232

CAT_ARGS="-e --number-nonblank -n -s -t -T"
assert 1233

CAT_ARGS="-e --number-nonblank -n -s -t -v"
assert 1234

CAT_ARGS="-e --number-nonblank -n -s -T -v"
assert 1235

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -t -T"
assert 1236

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -t -v"
assert 1237

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -T -v"
assert 1238

CAT_ARGS="-e --number-nonblank -n -t -T -v"
assert 1239

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -t"
assert 1240

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -T"
assert 1241

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -v"
assert 1242

CAT_ARGS="-e --number-nonblank --number -s -t -T"
assert 1243

CAT_ARGS="-e --number-nonblank --number -s -t -v"
assert 1244

CAT_ARGS="-e --number-nonblank --number -s -T -v"
assert 1245

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -t -T"
assert 1246

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -t -v"
assert 1247

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -T -v"
assert 1248

CAT_ARGS="-e --number-nonblank --number -t -T -v"
assert 1249

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -t -T"
assert 1250

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -t -v"
assert 1251

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -T -v"
assert 1252

CAT_ARGS="-e --number-nonblank -s -t -T -v"
assert 1253

CAT_ARGS="-e --number-nonblank --squeeze-blank -t -T -v"
assert 1254

CAT_ARGS="-e -n --number -s --squeeze-blank -t"
assert 1255

CAT_ARGS="-e -n --number -s --squeeze-blank -T"
assert 1256

CAT_ARGS="-e -n --number -s --squeeze-blank -v"
assert 1257

CAT_ARGS="-e -n --number -s -t -T"
assert 1258

CAT_ARGS="-e -n --number -s -t -v"
assert 1259

CAT_ARGS="-e -n --number -s -T -v"
assert 1260

CAT_ARGS="-e -n --number --squeeze-blank -t -T"
assert 1261

CAT_ARGS="-e -n --number --squeeze-blank -t -v"
assert 1262

CAT_ARGS="-e -n --number --squeeze-blank -T -v"
assert 1263

CAT_ARGS="-e -n --number -t -T -v"
assert 1264

CAT_ARGS="-e -n -s --squeeze-blank -t -T"
assert 1265

CAT_ARGS="-e -n -s --squeeze-blank -t -v"
assert 1266

CAT_ARGS="-e -n -s --squeeze-blank -T -v"
assert 1267

CAT_ARGS="-e -n -s -t -T -v"
assert 1268

CAT_ARGS="-e -n --squeeze-blank -t -T -v"
assert 1269

CAT_ARGS="-e --number -s --squeeze-blank -t -T"
assert 1270

CAT_ARGS="-e --number -s --squeeze-blank -t -v"
assert 1271

CAT_ARGS="-e --number -s --squeeze-blank -T -v"
assert 1272

CAT_ARGS="-e --number -s -t -T -v"
assert 1273

CAT_ARGS="-e --number --squeeze-blank -t -T -v"
assert 1274

CAT_ARGS="-e -s --squeeze-blank -t -T -v"
assert 1275

CAT_ARGS="-E -b --number-nonblank -n --number -s"
assert 1276

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank"
assert 1277

CAT_ARGS="-E -b --number-nonblank -n --number -t"
assert 1278

CAT_ARGS="-E -b --number-nonblank -n --number -T"
assert 1279

CAT_ARGS="-E -b --number-nonblank -n --number -v"
assert 1280

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank"
assert 1281

CAT_ARGS="-E -b --number-nonblank -n -s -t"
assert 1282

CAT_ARGS="-E -b --number-nonblank -n -s -T"
assert 1283

CAT_ARGS="-E -b --number-nonblank -n -s -v"
assert 1284

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -t"
assert 1285

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -T"
assert 1286

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -v"
assert 1287

CAT_ARGS="-E -b --number-nonblank -n -t -T"
assert 1288

CAT_ARGS="-E -b --number-nonblank -n -t -v"
assert 1289

CAT_ARGS="-E -b --number-nonblank -n -T -v"
assert 1290

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank"
assert 1291

CAT_ARGS="-E -b --number-nonblank --number -s -t"
assert 1292

CAT_ARGS="-E -b --number-nonblank --number -s -T"
assert 1293

CAT_ARGS="-E -b --number-nonblank --number -s -v"
assert 1294

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -t"
assert 1295

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -T"
assert 1296

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -v"
assert 1297

CAT_ARGS="-E -b --number-nonblank --number -t -T"
assert 1298

CAT_ARGS="-E -b --number-nonblank --number -t -v"
assert 1299

CAT_ARGS="-E -b --number-nonblank --number -T -v"
assert 1300

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -t"
assert 1301

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -T"
assert 1302

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -v"
assert 1303

CAT_ARGS="-E -b --number-nonblank -s -t -T"
assert 1304

CAT_ARGS="-E -b --number-nonblank -s -t -v"
assert 1305

CAT_ARGS="-E -b --number-nonblank -s -T -v"
assert 1306

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -t -T"
assert 1307

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -t -v"
assert 1308

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -T -v"
assert 1309

CAT_ARGS="-E -b --number-nonblank -t -T -v"
assert 1310

CAT_ARGS="-E -b -n --number -s --squeeze-blank"
assert 1311

CAT_ARGS="-E -b -n --number -s -t"
assert 1312

CAT_ARGS="-E -b -n --number -s -T"
assert 1313

CAT_ARGS="-E -b -n --number -s -v"
assert 1314

CAT_ARGS="-E -b -n --number --squeeze-blank -t"
assert 1315

CAT_ARGS="-E -b -n --number --squeeze-blank -T"
assert 1316

CAT_ARGS="-E -b -n --number --squeeze-blank -v"
assert 1317

CAT_ARGS="-E -b -n --number -t -T"
assert 1318

CAT_ARGS="-E -b -n --number -t -v"
assert 1319

CAT_ARGS="-E -b -n --number -T -v"
assert 1320

CAT_ARGS="-E -b -n -s --squeeze-blank -t"
assert 1321

CAT_ARGS="-E -b -n -s --squeeze-blank -T"
assert 1322

CAT_ARGS="-E -b -n -s --squeeze-blank -v"
assert 1323

CAT_ARGS="-E -b -n -s -t -T"
assert 1324

CAT_ARGS="-E -b -n -s -t -v"
assert 1325

CAT_ARGS="-E -b -n -s -T -v"
assert 1326

CAT_ARGS="-E -b -n --squeeze-blank -t -T"
assert 1327

CAT_ARGS="-E -b -n --squeeze-blank -t -v"
assert 1328

CAT_ARGS="-E -b -n --squeeze-blank -T -v"
assert 1329

CAT_ARGS="-E -b -n -t -T -v"
assert 1330

CAT_ARGS="-E -b --number -s --squeeze-blank -t"
assert 1331

CAT_ARGS="-E -b --number -s --squeeze-blank -T"
assert 1332

CAT_ARGS="-E -b --number -s --squeeze-blank -v"
assert 1333

CAT_ARGS="-E -b --number -s -t -T"
assert 1334

CAT_ARGS="-E -b --number -s -t -v"
assert 1335

CAT_ARGS="-E -b --number -s -T -v"
assert 1336

CAT_ARGS="-E -b --number --squeeze-blank -t -T"
assert 1337

CAT_ARGS="-E -b --number --squeeze-blank -t -v"
assert 1338

CAT_ARGS="-E -b --number --squeeze-blank -T -v"
assert 1339

CAT_ARGS="-E -b --number -t -T -v"
assert 1340

CAT_ARGS="-E -b -s --squeeze-blank -t -T"
assert 1341

CAT_ARGS="-E -b -s --squeeze-blank -t -v"
assert 1342

CAT_ARGS="-E -b -s --squeeze-blank -T -v"
assert 1343

CAT_ARGS="-E -b -s -t -T -v"
assert 1344

CAT_ARGS="-E -b --squeeze-blank -t -T -v"
assert 1345

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank"
assert 1346

CAT_ARGS="-E --number-nonblank -n --number -s -t"
assert 1347

CAT_ARGS="-E --number-nonblank -n --number -s -T"
assert 1348

CAT_ARGS="-E --number-nonblank -n --number -s -v"
assert 1349

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -t"
assert 1350

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -T"
assert 1351

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -v"
assert 1352

CAT_ARGS="-E --number-nonblank -n --number -t -T"
assert 1353

CAT_ARGS="-E --number-nonblank -n --number -t -v"
assert 1354

CAT_ARGS="-E --number-nonblank -n --number -T -v"
assert 1355

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -t"
assert 1356

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -T"
assert 1357

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -v"
assert 1358

CAT_ARGS="-E --number-nonblank -n -s -t -T"
assert 1359

CAT_ARGS="-E --number-nonblank -n -s -t -v"
assert 1360

CAT_ARGS="-E --number-nonblank -n -s -T -v"
assert 1361

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -t -T"
assert 1362

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -t -v"
assert 1363

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -T -v"
assert 1364

CAT_ARGS="-E --number-nonblank -n -t -T -v"
assert 1365

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -t"
assert 1366

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -T"
assert 1367

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -v"
assert 1368

CAT_ARGS="-E --number-nonblank --number -s -t -T"
assert 1369

CAT_ARGS="-E --number-nonblank --number -s -t -v"
assert 1370

CAT_ARGS="-E --number-nonblank --number -s -T -v"
assert 1371

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -t -T"
assert 1372

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -t -v"
assert 1373

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -T -v"
assert 1374

CAT_ARGS="-E --number-nonblank --number -t -T -v"
assert 1375

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -t -T"
assert 1376

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -t -v"
assert 1377

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -T -v"
assert 1378

CAT_ARGS="-E --number-nonblank -s -t -T -v"
assert 1379

CAT_ARGS="-E --number-nonblank --squeeze-blank -t -T -v"
assert 1380

CAT_ARGS="-E -n --number -s --squeeze-blank -t"
assert 1381

CAT_ARGS="-E -n --number -s --squeeze-blank -T"
assert 1382

CAT_ARGS="-E -n --number -s --squeeze-blank -v"
assert 1383

CAT_ARGS="-E -n --number -s -t -T"
assert 1384

CAT_ARGS="-E -n --number -s -t -v"
assert 1385

CAT_ARGS="-E -n --number -s -T -v"
assert 1386

CAT_ARGS="-E -n --number --squeeze-blank -t -T"
assert 1387

CAT_ARGS="-E -n --number --squeeze-blank -t -v"
assert 1388

CAT_ARGS="-E -n --number --squeeze-blank -T -v"
assert 1389

CAT_ARGS="-E -n --number -t -T -v"
assert 1390

CAT_ARGS="-E -n -s --squeeze-blank -t -T"
assert 1391

CAT_ARGS="-E -n -s --squeeze-blank -t -v"
assert 1392

CAT_ARGS="-E -n -s --squeeze-blank -T -v"
assert 1393

CAT_ARGS="-E -n -s -t -T -v"
assert 1394

CAT_ARGS="-E -n --squeeze-blank -t -T -v"
assert 1395

CAT_ARGS="-E --number -s --squeeze-blank -t -T"
assert 1396

CAT_ARGS="-E --number -s --squeeze-blank -t -v"
assert 1397

CAT_ARGS="-E --number -s --squeeze-blank -T -v"
assert 1398

CAT_ARGS="-E --number -s -t -T -v"
assert 1399

CAT_ARGS="-E --number --squeeze-blank -t -T -v"
assert 1400

CAT_ARGS="-E -s --squeeze-blank -t -T -v"
assert 1401

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank"
assert 1402

CAT_ARGS="-b --number-nonblank -n --number -s -t"
assert 1403

CAT_ARGS="-b --number-nonblank -n --number -s -T"
assert 1404

CAT_ARGS="-b --number-nonblank -n --number -s -v"
assert 1405

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -t"
assert 1406

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -T"
assert 1407

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -v"
assert 1408

CAT_ARGS="-b --number-nonblank -n --number -t -T"
assert 1409

CAT_ARGS="-b --number-nonblank -n --number -t -v"
assert 1410

CAT_ARGS="-b --number-nonblank -n --number -T -v"
assert 1411

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -t"
assert 1412

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -T"
assert 1413

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -v"
assert 1414

CAT_ARGS="-b --number-nonblank -n -s -t -T"
assert 1415

CAT_ARGS="-b --number-nonblank -n -s -t -v"
assert 1416

CAT_ARGS="-b --number-nonblank -n -s -T -v"
assert 1417

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -t -T"
assert 1418

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -t -v"
assert 1419

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -T -v"
assert 1420

CAT_ARGS="-b --number-nonblank -n -t -T -v"
assert 1421

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -t"
assert 1422

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -T"
assert 1423

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -v"
assert 1424

CAT_ARGS="-b --number-nonblank --number -s -t -T"
assert 1425

CAT_ARGS="-b --number-nonblank --number -s -t -v"
assert 1426

CAT_ARGS="-b --number-nonblank --number -s -T -v"
assert 1427

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -t -T"
assert 1428

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -t -v"
assert 1429

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -T -v"
assert 1430

CAT_ARGS="-b --number-nonblank --number -t -T -v"
assert 1431

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -t -T"
assert 1432

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -t -v"
assert 1433

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -T -v"
assert 1434

CAT_ARGS="-b --number-nonblank -s -t -T -v"
assert 1435

CAT_ARGS="-b --number-nonblank --squeeze-blank -t -T -v"
assert 1436

CAT_ARGS="-b -n --number -s --squeeze-blank -t"
assert 1437

CAT_ARGS="-b -n --number -s --squeeze-blank -T"
assert 1438

CAT_ARGS="-b -n --number -s --squeeze-blank -v"
assert 1439

CAT_ARGS="-b -n --number -s -t -T"
assert 1440

CAT_ARGS="-b -n --number -s -t -v"
assert 1441

CAT_ARGS="-b -n --number -s -T -v"
assert 1442

CAT_ARGS="-b -n --number --squeeze-blank -t -T"
assert 1443

CAT_ARGS="-b -n --number --squeeze-blank -t -v"
assert 1444

CAT_ARGS="-b -n --number --squeeze-blank -T -v"
assert 1445

CAT_ARGS="-b -n --number -t -T -v"
assert 1446

CAT_ARGS="-b -n -s --squeeze-blank -t -T"
assert 1447

CAT_ARGS="-b -n -s --squeeze-blank -t -v"
assert 1448

CAT_ARGS="-b -n -s --squeeze-blank -T -v"
assert 1449

CAT_ARGS="-b -n -s -t -T -v"
assert 1450

CAT_ARGS="-b -n --squeeze-blank -t -T -v"
assert 1451

CAT_ARGS="-b --number -s --squeeze-blank -t -T"
assert 1452

CAT_ARGS="-b --number -s --squeeze-blank -t -v"
assert 1453

CAT_ARGS="-b --number -s --squeeze-blank -T -v"
assert 1454

CAT_ARGS="-b --number -s -t -T -v"
assert 1455

CAT_ARGS="-b --number --squeeze-blank -t -T -v"
assert 1456

CAT_ARGS="-b -s --squeeze-blank -t -T -v"
assert 1457

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -t"
assert 1458

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -T"
assert 1459

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -v"
assert 1460

CAT_ARGS="--number-nonblank -n --number -s -t -T"
assert 1461

CAT_ARGS="--number-nonblank -n --number -s -t -v"
assert 1462

CAT_ARGS="--number-nonblank -n --number -s -T -v"
assert 1463

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -t -T"
assert 1464

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -t -v"
assert 1465

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -T -v"
assert 1466

CAT_ARGS="--number-nonblank -n --number -t -T -v"
assert 1467

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -t -T"
assert 1468

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -t -v"
assert 1469

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -T -v"
assert 1470

CAT_ARGS="--number-nonblank -n -s -t -T -v"
assert 1471

CAT_ARGS="--number-nonblank -n --squeeze-blank -t -T -v"
assert 1472

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -t -T"
assert 1473

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -t -v"
assert 1474

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -T -v"
assert 1475

CAT_ARGS="--number-nonblank --number -s -t -T -v"
assert 1476

CAT_ARGS="--number-nonblank --number --squeeze-blank -t -T -v"
assert 1477

CAT_ARGS="--number-nonblank -s --squeeze-blank -t -T -v"
assert 1478

CAT_ARGS="-n --number -s --squeeze-blank -t -T"
assert 1479

CAT_ARGS="-n --number -s --squeeze-blank -t -v"
assert 1480

CAT_ARGS="-n --number -s --squeeze-blank -T -v"
assert 1481

CAT_ARGS="-n --number -s -t -T -v"
assert 1482

CAT_ARGS="-n --number --squeeze-blank -t -T -v"
assert 1483

CAT_ARGS="-n -s --squeeze-blank -t -T -v"
assert 1484

CAT_ARGS="--number -s --squeeze-blank -t -T -v"
assert 1485

CAT_ARGS="-e -E -b --number-nonblank -n --number -s"
assert 1486

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank"
assert 1487

CAT_ARGS="-e -E -b --number-nonblank -n --number -t"
assert 1488

CAT_ARGS="-e -E -b --number-nonblank -n --number -T"
assert 1489

CAT_ARGS="-e -E -b --number-nonblank -n --number -v"
assert 1490

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank"
assert 1491

CAT_ARGS="-e -E -b --number-nonblank -n -s -t"
assert 1492

CAT_ARGS="-e -E -b --number-nonblank -n -s -T"
assert 1493

CAT_ARGS="-e -E -b --number-nonblank -n -s -v"
assert 1494

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -t"
assert 1495

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -T"
assert 1496

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -v"
assert 1497

CAT_ARGS="-e -E -b --number-nonblank -n -t -T"
assert 1498

CAT_ARGS="-e -E -b --number-nonblank -n -t -v"
assert 1499

CAT_ARGS="-e -E -b --number-nonblank -n -T -v"
assert 1500

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank"
assert 1501

CAT_ARGS="-e -E -b --number-nonblank --number -s -t"
assert 1502

CAT_ARGS="-e -E -b --number-nonblank --number -s -T"
assert 1503

CAT_ARGS="-e -E -b --number-nonblank --number -s -v"
assert 1504

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -t"
assert 1505

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -T"
assert 1506

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -v"
assert 1507

CAT_ARGS="-e -E -b --number-nonblank --number -t -T"
assert 1508

CAT_ARGS="-e -E -b --number-nonblank --number -t -v"
assert 1509

CAT_ARGS="-e -E -b --number-nonblank --number -T -v"
assert 1510

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -t"
assert 1511

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -T"
assert 1512

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -v"
assert 1513

CAT_ARGS="-e -E -b --number-nonblank -s -t -T"
assert 1514

CAT_ARGS="-e -E -b --number-nonblank -s -t -v"
assert 1515

CAT_ARGS="-e -E -b --number-nonblank -s -T -v"
assert 1516

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -t -T"
assert 1517

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -t -v"
assert 1518

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -T -v"
assert 1519

CAT_ARGS="-e -E -b --number-nonblank -t -T -v"
assert 1520

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank"
assert 1521

CAT_ARGS="-e -E -b -n --number -s -t"
assert 1522

CAT_ARGS="-e -E -b -n --number -s -T"
assert 1523

CAT_ARGS="-e -E -b -n --number -s -v"
assert 1524

CAT_ARGS="-e -E -b -n --number --squeeze-blank -t"
assert 1525

CAT_ARGS="-e -E -b -n --number --squeeze-blank -T"
assert 1526

CAT_ARGS="-e -E -b -n --number --squeeze-blank -v"
assert 1527

CAT_ARGS="-e -E -b -n --number -t -T"
assert 1528

CAT_ARGS="-e -E -b -n --number -t -v"
assert 1529

CAT_ARGS="-e -E -b -n --number -T -v"
assert 1530

CAT_ARGS="-e -E -b -n -s --squeeze-blank -t"
assert 1531

CAT_ARGS="-e -E -b -n -s --squeeze-blank -T"
assert 1532

CAT_ARGS="-e -E -b -n -s --squeeze-blank -v"
assert 1533

CAT_ARGS="-e -E -b -n -s -t -T"
assert 1534

CAT_ARGS="-e -E -b -n -s -t -v"
assert 1535

CAT_ARGS="-e -E -b -n -s -T -v"
assert 1536

CAT_ARGS="-e -E -b -n --squeeze-blank -t -T"
assert 1537

CAT_ARGS="-e -E -b -n --squeeze-blank -t -v"
assert 1538

CAT_ARGS="-e -E -b -n --squeeze-blank -T -v"
assert 1539

CAT_ARGS="-e -E -b -n -t -T -v"
assert 1540

CAT_ARGS="-e -E -b --number -s --squeeze-blank -t"
assert 1541

CAT_ARGS="-e -E -b --number -s --squeeze-blank -T"
assert 1542

CAT_ARGS="-e -E -b --number -s --squeeze-blank -v"
assert 1543

CAT_ARGS="-e -E -b --number -s -t -T"
assert 1544

CAT_ARGS="-e -E -b --number -s -t -v"
assert 1545

CAT_ARGS="-e -E -b --number -s -T -v"
assert 1546

CAT_ARGS="-e -E -b --number --squeeze-blank -t -T"
assert 1547

CAT_ARGS="-e -E -b --number --squeeze-blank -t -v"
assert 1548

CAT_ARGS="-e -E -b --number --squeeze-blank -T -v"
assert 1549

CAT_ARGS="-e -E -b --number -t -T -v"
assert 1550

CAT_ARGS="-e -E -b -s --squeeze-blank -t -T"
assert 1551

CAT_ARGS="-e -E -b -s --squeeze-blank -t -v"
assert 1552

CAT_ARGS="-e -E -b -s --squeeze-blank -T -v"
assert 1553

CAT_ARGS="-e -E -b -s -t -T -v"
assert 1554

CAT_ARGS="-e -E -b --squeeze-blank -t -T -v"
assert 1555

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank"
assert 1556

CAT_ARGS="-e -E --number-nonblank -n --number -s -t"
assert 1557

CAT_ARGS="-e -E --number-nonblank -n --number -s -T"
assert 1558

CAT_ARGS="-e -E --number-nonblank -n --number -s -v"
assert 1559

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -t"
assert 1560

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -T"
assert 1561

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -v"
assert 1562

CAT_ARGS="-e -E --number-nonblank -n --number -t -T"
assert 1563

CAT_ARGS="-e -E --number-nonblank -n --number -t -v"
assert 1564

CAT_ARGS="-e -E --number-nonblank -n --number -T -v"
assert 1565

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -t"
assert 1566

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -T"
assert 1567

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -v"
assert 1568

CAT_ARGS="-e -E --number-nonblank -n -s -t -T"
assert 1569

CAT_ARGS="-e -E --number-nonblank -n -s -t -v"
assert 1570

CAT_ARGS="-e -E --number-nonblank -n -s -T -v"
assert 1571

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -t -T"
assert 1572

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -t -v"
assert 1573

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -T -v"
assert 1574

CAT_ARGS="-e -E --number-nonblank -n -t -T -v"
assert 1575

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -t"
assert 1576

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -T"
assert 1577

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -v"
assert 1578

CAT_ARGS="-e -E --number-nonblank --number -s -t -T"
assert 1579

CAT_ARGS="-e -E --number-nonblank --number -s -t -v"
assert 1580

CAT_ARGS="-e -E --number-nonblank --number -s -T -v"
assert 1581

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -t -T"
assert 1582

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -t -v"
assert 1583

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -T -v"
assert 1584

CAT_ARGS="-e -E --number-nonblank --number -t -T -v"
assert 1585

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -t -T"
assert 1586

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -t -v"
assert 1587

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -T -v"
assert 1588

CAT_ARGS="-e -E --number-nonblank -s -t -T -v"
assert 1589

CAT_ARGS="-e -E --number-nonblank --squeeze-blank -t -T -v"
assert 1590

CAT_ARGS="-e -E -n --number -s --squeeze-blank -t"
assert 1591

CAT_ARGS="-e -E -n --number -s --squeeze-blank -T"
assert 1592

CAT_ARGS="-e -E -n --number -s --squeeze-blank -v"
assert 1593

CAT_ARGS="-e -E -n --number -s -t -T"
assert 1594

CAT_ARGS="-e -E -n --number -s -t -v"
assert 1595

CAT_ARGS="-e -E -n --number -s -T -v"
assert 1596

CAT_ARGS="-e -E -n --number --squeeze-blank -t -T"
assert 1597

CAT_ARGS="-e -E -n --number --squeeze-blank -t -v"
assert 1598

CAT_ARGS="-e -E -n --number --squeeze-blank -T -v"
assert 1599

CAT_ARGS="-e -E -n --number -t -T -v"
assert 1600

CAT_ARGS="-e -E -n -s --squeeze-blank -t -T"
assert 1601

CAT_ARGS="-e -E -n -s --squeeze-blank -t -v"
assert 1602

CAT_ARGS="-e -E -n -s --squeeze-blank -T -v"
assert 1603

CAT_ARGS="-e -E -n -s -t -T -v"
assert 1604

CAT_ARGS="-e -E -n --squeeze-blank -t -T -v"
assert 1605

CAT_ARGS="-e -E --number -s --squeeze-blank -t -T"
assert 1606

CAT_ARGS="-e -E --number -s --squeeze-blank -t -v"
assert 1607

CAT_ARGS="-e -E --number -s --squeeze-blank -T -v"
assert 1608

CAT_ARGS="-e -E --number -s -t -T -v"
assert 1609

CAT_ARGS="-e -E --number --squeeze-blank -t -T -v"
assert 1610

CAT_ARGS="-e -E -s --squeeze-blank -t -T -v"
assert 1611

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank"
assert 1612

CAT_ARGS="-e -b --number-nonblank -n --number -s -t"
assert 1613

CAT_ARGS="-e -b --number-nonblank -n --number -s -T"
assert 1614

CAT_ARGS="-e -b --number-nonblank -n --number -s -v"
assert 1615

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -t"
assert 1616

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -T"
assert 1617

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -v"
assert 1618

CAT_ARGS="-e -b --number-nonblank -n --number -t -T"
assert 1619

CAT_ARGS="-e -b --number-nonblank -n --number -t -v"
assert 1620

CAT_ARGS="-e -b --number-nonblank -n --number -T -v"
assert 1621

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -t"
assert 1622

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -T"
assert 1623

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -v"
assert 1624

CAT_ARGS="-e -b --number-nonblank -n -s -t -T"
assert 1625

CAT_ARGS="-e -b --number-nonblank -n -s -t -v"
assert 1626

CAT_ARGS="-e -b --number-nonblank -n -s -T -v"
assert 1627

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -t -T"
assert 1628

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -t -v"
assert 1629

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -T -v"
assert 1630

CAT_ARGS="-e -b --number-nonblank -n -t -T -v"
assert 1631

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -t"
assert 1632

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -T"
assert 1633

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -v"
assert 1634

CAT_ARGS="-e -b --number-nonblank --number -s -t -T"
assert 1635

CAT_ARGS="-e -b --number-nonblank --number -s -t -v"
assert 1636

CAT_ARGS="-e -b --number-nonblank --number -s -T -v"
assert 1637

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -t -T"
assert 1638

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -t -v"
assert 1639

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -T -v"
assert 1640

CAT_ARGS="-e -b --number-nonblank --number -t -T -v"
assert 1641

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -t -T"
assert 1642

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -t -v"
assert 1643

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -T -v"
assert 1644

CAT_ARGS="-e -b --number-nonblank -s -t -T -v"
assert 1645

CAT_ARGS="-e -b --number-nonblank --squeeze-blank -t -T -v"
assert 1646

CAT_ARGS="-e -b -n --number -s --squeeze-blank -t"
assert 1647

CAT_ARGS="-e -b -n --number -s --squeeze-blank -T"
assert 1648

CAT_ARGS="-e -b -n --number -s --squeeze-blank -v"
assert 1649

CAT_ARGS="-e -b -n --number -s -t -T"
assert 1650

CAT_ARGS="-e -b -n --number -s -t -v"
assert 1651

CAT_ARGS="-e -b -n --number -s -T -v"
assert 1652

CAT_ARGS="-e -b -n --number --squeeze-blank -t -T"
assert 1653

CAT_ARGS="-e -b -n --number --squeeze-blank -t -v"
assert 1654

CAT_ARGS="-e -b -n --number --squeeze-blank -T -v"
assert 1655

CAT_ARGS="-e -b -n --number -t -T -v"
assert 1656

CAT_ARGS="-e -b -n -s --squeeze-blank -t -T"
assert 1657

CAT_ARGS="-e -b -n -s --squeeze-blank -t -v"
assert 1658

CAT_ARGS="-e -b -n -s --squeeze-blank -T -v"
assert 1659

CAT_ARGS="-e -b -n -s -t -T -v"
assert 1660

CAT_ARGS="-e -b -n --squeeze-blank -t -T -v"
assert 1661

CAT_ARGS="-e -b --number -s --squeeze-blank -t -T"
assert 1662

CAT_ARGS="-e -b --number -s --squeeze-blank -t -v"
assert 1663

CAT_ARGS="-e -b --number -s --squeeze-blank -T -v"
assert 1664

CAT_ARGS="-e -b --number -s -t -T -v"
assert 1665

CAT_ARGS="-e -b --number --squeeze-blank -t -T -v"
assert 1666

CAT_ARGS="-e -b -s --squeeze-blank -t -T -v"
assert 1667

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -t"
assert 1668

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -T"
assert 1669

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -v"
assert 1670

CAT_ARGS="-e --number-nonblank -n --number -s -t -T"
assert 1671

CAT_ARGS="-e --number-nonblank -n --number -s -t -v"
assert 1672

CAT_ARGS="-e --number-nonblank -n --number -s -T -v"
assert 1673

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -t -T"
assert 1674

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -t -v"
assert 1675

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -T -v"
assert 1676

CAT_ARGS="-e --number-nonblank -n --number -t -T -v"
assert 1677

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -t -T"
assert 1678

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -t -v"
assert 1679

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -T -v"
assert 1680

CAT_ARGS="-e --number-nonblank -n -s -t -T -v"
assert 1681

CAT_ARGS="-e --number-nonblank -n --squeeze-blank -t -T -v"
assert 1682

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -t -T"
assert 1683

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -t -v"
assert 1684

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -T -v"
assert 1685

CAT_ARGS="-e --number-nonblank --number -s -t -T -v"
assert 1686

CAT_ARGS="-e --number-nonblank --number --squeeze-blank -t -T -v"
assert 1687

CAT_ARGS="-e --number-nonblank -s --squeeze-blank -t -T -v"
assert 1688

CAT_ARGS="-e -n --number -s --squeeze-blank -t -T"
assert 1689

CAT_ARGS="-e -n --number -s --squeeze-blank -t -v"
assert 1690

CAT_ARGS="-e -n --number -s --squeeze-blank -T -v"
assert 1691

CAT_ARGS="-e -n --number -s -t -T -v"
assert 1692

CAT_ARGS="-e -n --number --squeeze-blank -t -T -v"
assert 1693

CAT_ARGS="-e -n -s --squeeze-blank -t -T -v"
assert 1694

CAT_ARGS="-e --number -s --squeeze-blank -t -T -v"
assert 1695

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank"
assert 1696

CAT_ARGS="-E -b --number-nonblank -n --number -s -t"
assert 1697

CAT_ARGS="-E -b --number-nonblank -n --number -s -T"
assert 1698

CAT_ARGS="-E -b --number-nonblank -n --number -s -v"
assert 1699

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -t"
assert 1700

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -T"
assert 1701

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -v"
assert 1702

CAT_ARGS="-E -b --number-nonblank -n --number -t -T"
assert 1703

CAT_ARGS="-E -b --number-nonblank -n --number -t -v"
assert 1704

CAT_ARGS="-E -b --number-nonblank -n --number -T -v"
assert 1705

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -t"
assert 1706

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -T"
assert 1707

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -v"
assert 1708

CAT_ARGS="-E -b --number-nonblank -n -s -t -T"
assert 1709

CAT_ARGS="-E -b --number-nonblank -n -s -t -v"
assert 1710

CAT_ARGS="-E -b --number-nonblank -n -s -T -v"
assert 1711

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -t -T"
assert 1712

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -t -v"
assert 1713

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -T -v"
assert 1714

CAT_ARGS="-E -b --number-nonblank -n -t -T -v"
assert 1715

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -t"
assert 1716

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -T"
assert 1717

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -v"
assert 1718

CAT_ARGS="-E -b --number-nonblank --number -s -t -T"
assert 1719

CAT_ARGS="-E -b --number-nonblank --number -s -t -v"
assert 1720

CAT_ARGS="-E -b --number-nonblank --number -s -T -v"
assert 1721

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -t -T"
assert 1722

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -t -v"
assert 1723

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -T -v"
assert 1724

CAT_ARGS="-E -b --number-nonblank --number -t -T -v"
assert 1725

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -t -T"
assert 1726

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -t -v"
assert 1727

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -T -v"
assert 1728

CAT_ARGS="-E -b --number-nonblank -s -t -T -v"
assert 1729

CAT_ARGS="-E -b --number-nonblank --squeeze-blank -t -T -v"
assert 1730

CAT_ARGS="-E -b -n --number -s --squeeze-blank -t"
assert 1731

CAT_ARGS="-E -b -n --number -s --squeeze-blank -T"
assert 1732

CAT_ARGS="-E -b -n --number -s --squeeze-blank -v"
assert 1733

CAT_ARGS="-E -b -n --number -s -t -T"
assert 1734

CAT_ARGS="-E -b -n --number -s -t -v"
assert 1735

CAT_ARGS="-E -b -n --number -s -T -v"
assert 1736

CAT_ARGS="-E -b -n --number --squeeze-blank -t -T"
assert 1737

CAT_ARGS="-E -b -n --number --squeeze-blank -t -v"
assert 1738

CAT_ARGS="-E -b -n --number --squeeze-blank -T -v"
assert 1739

CAT_ARGS="-E -b -n --number -t -T -v"
assert 1740

CAT_ARGS="-E -b -n -s --squeeze-blank -t -T"
assert 1741

CAT_ARGS="-E -b -n -s --squeeze-blank -t -v"
assert 1742

CAT_ARGS="-E -b -n -s --squeeze-blank -T -v"
assert 1743

CAT_ARGS="-E -b -n -s -t -T -v"
assert 1744

CAT_ARGS="-E -b -n --squeeze-blank -t -T -v"
assert 1745

CAT_ARGS="-E -b --number -s --squeeze-blank -t -T"
assert 1746

CAT_ARGS="-E -b --number -s --squeeze-blank -t -v"
assert 1747

CAT_ARGS="-E -b --number -s --squeeze-blank -T -v"
assert 1748

CAT_ARGS="-E -b --number -s -t -T -v"
assert 1749

CAT_ARGS="-E -b --number --squeeze-blank -t -T -v"
assert 1750

CAT_ARGS="-E -b -s --squeeze-blank -t -T -v"
assert 1751

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -t"
assert 1752

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -T"
assert 1753

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -v"
assert 1754

CAT_ARGS="-E --number-nonblank -n --number -s -t -T"
assert 1755

CAT_ARGS="-E --number-nonblank -n --number -s -t -v"
assert 1756

CAT_ARGS="-E --number-nonblank -n --number -s -T -v"
assert 1757

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -t -T"
assert 1758

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -t -v"
assert 1759

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -T -v"
assert 1760

CAT_ARGS="-E --number-nonblank -n --number -t -T -v"
assert 1761

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -t -T"
assert 1762

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -t -v"
assert 1763

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -T -v"
assert 1764

CAT_ARGS="-E --number-nonblank -n -s -t -T -v"
assert 1765

CAT_ARGS="-E --number-nonblank -n --squeeze-blank -t -T -v"
assert 1766

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -t -T"
assert 1767

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -t -v"
assert 1768

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -T -v"
assert 1769

CAT_ARGS="-E --number-nonblank --number -s -t -T -v"
assert 1770

CAT_ARGS="-E --number-nonblank --number --squeeze-blank -t -T -v"
assert 1771

CAT_ARGS="-E --number-nonblank -s --squeeze-blank -t -T -v"
assert 1772

CAT_ARGS="-E -n --number -s --squeeze-blank -t -T"
assert 1773

CAT_ARGS="-E -n --number -s --squeeze-blank -t -v"
assert 1774

CAT_ARGS="-E -n --number -s --squeeze-blank -T -v"
assert 1775

CAT_ARGS="-E -n --number -s -t -T -v"
assert 1776

CAT_ARGS="-E -n --number --squeeze-blank -t -T -v"
assert 1777

CAT_ARGS="-E -n -s --squeeze-blank -t -T -v"
assert 1778

CAT_ARGS="-E --number -s --squeeze-blank -t -T -v"
assert 1779

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -t"
assert 1780

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -T"
assert 1781

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -v"
assert 1782

CAT_ARGS="-b --number-nonblank -n --number -s -t -T"
assert 1783

CAT_ARGS="-b --number-nonblank -n --number -s -t -v"
assert 1784

CAT_ARGS="-b --number-nonblank -n --number -s -T -v"
assert 1785

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -t -T"
assert 1786

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -t -v"
assert 1787

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -T -v"
assert 1788

CAT_ARGS="-b --number-nonblank -n --number -t -T -v"
assert 1789

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -t -T"
assert 1790

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -t -v"
assert 1791

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -T -v"
assert 1792

CAT_ARGS="-b --number-nonblank -n -s -t -T -v"
assert 1793

CAT_ARGS="-b --number-nonblank -n --squeeze-blank -t -T -v"
assert 1794

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -t -T"
assert 1795

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -t -v"
assert 1796

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -T -v"
assert 1797

CAT_ARGS="-b --number-nonblank --number -s -t -T -v"
assert 1798

CAT_ARGS="-b --number-nonblank --number --squeeze-blank -t -T -v"
assert 1799

CAT_ARGS="-b --number-nonblank -s --squeeze-blank -t -T -v"
assert 1800

CAT_ARGS="-b -n --number -s --squeeze-blank -t -T"
assert 1801

CAT_ARGS="-b -n --number -s --squeeze-blank -t -v"
assert 1802

CAT_ARGS="-b -n --number -s --squeeze-blank -T -v"
assert 1803

CAT_ARGS="-b -n --number -s -t -T -v"
assert 1804

CAT_ARGS="-b -n --number --squeeze-blank -t -T -v"
assert 1805

CAT_ARGS="-b -n -s --squeeze-blank -t -T -v"
assert 1806

CAT_ARGS="-b --number -s --squeeze-blank -t -T -v"
assert 1807

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -t -T"
assert 1808

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -t -v"
assert 1809

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -T -v"
assert 1810

CAT_ARGS="--number-nonblank -n --number -s -t -T -v"
assert 1811

CAT_ARGS="--number-nonblank -n --number --squeeze-blank -t -T -v"
assert 1812

CAT_ARGS="--number-nonblank -n -s --squeeze-blank -t -T -v"
assert 1813

CAT_ARGS="--number-nonblank --number -s --squeeze-blank -t -T -v"
assert 1814

CAT_ARGS="-n --number -s --squeeze-blank -t -T -v"
assert 1815

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank"
assert 1816

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -t"
assert 1817

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -T"
assert 1818

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -v"
assert 1819

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -t"
assert 1820

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -T"
assert 1821

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -v"
assert 1822

CAT_ARGS="-e -E -b --number-nonblank -n --number -t -T"
assert 1823

CAT_ARGS="-e -E -b --number-nonblank -n --number -t -v"
assert 1824

CAT_ARGS="-e -E -b --number-nonblank -n --number -T -v"
assert 1825

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -t"
assert 1826

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -T"
assert 1827

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -v"
assert 1828

CAT_ARGS="-e -E -b --number-nonblank -n -s -t -T"
assert 1829

CAT_ARGS="-e -E -b --number-nonblank -n -s -t -v"
assert 1830

CAT_ARGS="-e -E -b --number-nonblank -n -s -T -v"
assert 1831

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -t -T"
assert 1832

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -t -v"
assert 1833

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -T -v"
assert 1834

CAT_ARGS="-e -E -b --number-nonblank -n -t -T -v"
assert 1835

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -t"
assert 1836

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -T"
assert 1837

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -v"
assert 1838

CAT_ARGS="-e -E -b --number-nonblank --number -s -t -T"
assert 1839

CAT_ARGS="-e -E -b --number-nonblank --number -s -t -v"
assert 1840

CAT_ARGS="-e -E -b --number-nonblank --number -s -T -v"
assert 1841

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -t -T"
assert 1842

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -t -v"
assert 1843

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -T -v"
assert 1844

CAT_ARGS="-e -E -b --number-nonblank --number -t -T -v"
assert 1845

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -t -T"
assert 1846

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -t -v"
assert 1847

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -T -v"
assert 1848

CAT_ARGS="-e -E -b --number-nonblank -s -t -T -v"
assert 1849

CAT_ARGS="-e -E -b --number-nonblank --squeeze-blank -t -T -v"
assert 1850

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -t"
assert 1851

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -T"
assert 1852

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -v"
assert 1853

CAT_ARGS="-e -E -b -n --number -s -t -T"
assert 1854

CAT_ARGS="-e -E -b -n --number -s -t -v"
assert 1855

CAT_ARGS="-e -E -b -n --number -s -T -v"
assert 1856

CAT_ARGS="-e -E -b -n --number --squeeze-blank -t -T"
assert 1857

CAT_ARGS="-e -E -b -n --number --squeeze-blank -t -v"
assert 1858

CAT_ARGS="-e -E -b -n --number --squeeze-blank -T -v"
assert 1859

CAT_ARGS="-e -E -b -n --number -t -T -v"
assert 1860

CAT_ARGS="-e -E -b -n -s --squeeze-blank -t -T"
assert 1861

CAT_ARGS="-e -E -b -n -s --squeeze-blank -t -v"
assert 1862

CAT_ARGS="-e -E -b -n -s --squeeze-blank -T -v"
assert 1863

CAT_ARGS="-e -E -b -n -s -t -T -v"
assert 1864

CAT_ARGS="-e -E -b -n --squeeze-blank -t -T -v"
assert 1865

CAT_ARGS="-e -E -b --number -s --squeeze-blank -t -T"
assert 1866

CAT_ARGS="-e -E -b --number -s --squeeze-blank -t -v"
assert 1867

CAT_ARGS="-e -E -b --number -s --squeeze-blank -T -v"
assert 1868

CAT_ARGS="-e -E -b --number -s -t -T -v"
assert 1869

CAT_ARGS="-e -E -b --number --squeeze-blank -t -T -v"
assert 1870

CAT_ARGS="-e -E -b -s --squeeze-blank -t -T -v"
assert 1871

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -t"
assert 1872

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -T"
assert 1873

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -v"
assert 1874

CAT_ARGS="-e -E --number-nonblank -n --number -s -t -T"
assert 1875

CAT_ARGS="-e -E --number-nonblank -n --number -s -t -v"
assert 1876

CAT_ARGS="-e -E --number-nonblank -n --number -s -T -v"
assert 1877

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -t -T"
assert 1878

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -t -v"
assert 1879

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -T -v"
assert 1880

CAT_ARGS="-e -E --number-nonblank -n --number -t -T -v"
assert 1881

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -t -T"
assert 1882

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -t -v"
assert 1883

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -T -v"
assert 1884

CAT_ARGS="-e -E --number-nonblank -n -s -t -T -v"
assert 1885

CAT_ARGS="-e -E --number-nonblank -n --squeeze-blank -t -T -v"
assert 1886

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -t -T"
assert 1887

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -t -v"
assert 1888

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -T -v"
assert 1889

CAT_ARGS="-e -E --number-nonblank --number -s -t -T -v"
assert 1890

CAT_ARGS="-e -E --number-nonblank --number --squeeze-blank -t -T -v"
assert 1891

CAT_ARGS="-e -E --number-nonblank -s --squeeze-blank -t -T -v"
assert 1892

CAT_ARGS="-e -E -n --number -s --squeeze-blank -t -T"
assert 1893

CAT_ARGS="-e -E -n --number -s --squeeze-blank -t -v"
assert 1894

CAT_ARGS="-e -E -n --number -s --squeeze-blank -T -v"
assert 1895

CAT_ARGS="-e -E -n --number -s -t -T -v"
assert 1896

CAT_ARGS="-e -E -n --number --squeeze-blank -t -T -v"
assert 1897

CAT_ARGS="-e -E -n -s --squeeze-blank -t -T -v"
assert 1898

CAT_ARGS="-e -E --number -s --squeeze-blank -t -T -v"
assert 1899

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -t"
assert 1900

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -T"
assert 1901

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -v"
assert 1902

CAT_ARGS="-e -b --number-nonblank -n --number -s -t -T"
assert 1903

CAT_ARGS="-e -b --number-nonblank -n --number -s -t -v"
assert 1904

CAT_ARGS="-e -b --number-nonblank -n --number -s -T -v"
assert 1905

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -t -T"
assert 1906

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -t -v"
assert 1907

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -T -v"
assert 1908

CAT_ARGS="-e -b --number-nonblank -n --number -t -T -v"
assert 1909

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -t -T"
assert 1910

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -t -v"
assert 1911

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -T -v"
assert 1912

CAT_ARGS="-e -b --number-nonblank -n -s -t -T -v"
assert 1913

CAT_ARGS="-e -b --number-nonblank -n --squeeze-blank -t -T -v"
assert 1914

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -t -T"
assert 1915

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -t -v"
assert 1916

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -T -v"
assert 1917

CAT_ARGS="-e -b --number-nonblank --number -s -t -T -v"
assert 1918

CAT_ARGS="-e -b --number-nonblank --number --squeeze-blank -t -T -v"
assert 1919

CAT_ARGS="-e -b --number-nonblank -s --squeeze-blank -t -T -v"
assert 1920

CAT_ARGS="-e -b -n --number -s --squeeze-blank -t -T"
assert 1921

CAT_ARGS="-e -b -n --number -s --squeeze-blank -t -v"
assert 1922

CAT_ARGS="-e -b -n --number -s --squeeze-blank -T -v"
assert 1923

CAT_ARGS="-e -b -n --number -s -t -T -v"
assert 1924

CAT_ARGS="-e -b -n --number --squeeze-blank -t -T -v"
assert 1925

CAT_ARGS="-e -b -n -s --squeeze-blank -t -T -v"
assert 1926

CAT_ARGS="-e -b --number -s --squeeze-blank -t -T -v"
assert 1927

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 1928

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 1929

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 1930

CAT_ARGS="-e --number-nonblank -n --number -s -t -T -v"
assert 1931

CAT_ARGS="-e --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 1932

CAT_ARGS="-e --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 1933

CAT_ARGS="-e --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 1934

CAT_ARGS="-e -n --number -s --squeeze-blank -t -T -v"
assert 1935

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -t"
assert 1936

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -T"
assert 1937

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -v"
assert 1938

CAT_ARGS="-E -b --number-nonblank -n --number -s -t -T"
assert 1939

CAT_ARGS="-E -b --number-nonblank -n --number -s -t -v"
assert 1940

CAT_ARGS="-E -b --number-nonblank -n --number -s -T -v"
assert 1941

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -t -T"
assert 1942

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -t -v"
assert 1943

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -T -v"
assert 1944

CAT_ARGS="-E -b --number-nonblank -n --number -t -T -v"
assert 1945

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -t -T"
assert 1946

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -t -v"
assert 1947

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -T -v"
assert 1948

CAT_ARGS="-E -b --number-nonblank -n -s -t -T -v"
assert 1949

CAT_ARGS="-E -b --number-nonblank -n --squeeze-blank -t -T -v"
assert 1950

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -t -T"
assert 1951

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -t -v"
assert 1952

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -T -v"
assert 1953

CAT_ARGS="-E -b --number-nonblank --number -s -t -T -v"
assert 1954

CAT_ARGS="-E -b --number-nonblank --number --squeeze-blank -t -T -v"
assert 1955

CAT_ARGS="-E -b --number-nonblank -s --squeeze-blank -t -T -v"
assert 1956

CAT_ARGS="-E -b -n --number -s --squeeze-blank -t -T"
assert 1957

CAT_ARGS="-E -b -n --number -s --squeeze-blank -t -v"
assert 1958

CAT_ARGS="-E -b -n --number -s --squeeze-blank -T -v"
assert 1959

CAT_ARGS="-E -b -n --number -s -t -T -v"
assert 1960

CAT_ARGS="-E -b -n --number --squeeze-blank -t -T -v"
assert 1961

CAT_ARGS="-E -b -n -s --squeeze-blank -t -T -v"
assert 1962

CAT_ARGS="-E -b --number -s --squeeze-blank -t -T -v"
assert 1963

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 1964

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 1965

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 1966

CAT_ARGS="-E --number-nonblank -n --number -s -t -T -v"
assert 1967

CAT_ARGS="-E --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 1968

CAT_ARGS="-E --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 1969

CAT_ARGS="-E --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 1970

CAT_ARGS="-E -n --number -s --squeeze-blank -t -T -v"
assert 1971

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 1972

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 1973

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 1974

CAT_ARGS="-b --number-nonblank -n --number -s -t -T -v"
assert 1975

CAT_ARGS="-b --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 1976

CAT_ARGS="-b --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 1977

CAT_ARGS="-b --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 1978

CAT_ARGS="-b -n --number -s --squeeze-blank -t -T -v"
assert 1979

CAT_ARGS="--number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 1980

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -t"
assert 1981

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -T"
assert 1982

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -v"
assert 1983

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -t -T"
assert 1984

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -t -v"
assert 1985

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -T -v"
assert 1986

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -t -T"
assert 1987

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -t -v"
assert 1988

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -T -v"
assert 1989

CAT_ARGS="-e -E -b --number-nonblank -n --number -t -T -v"
assert 1990

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -t -T"
assert 1991

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -t -v"
assert 1992

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -T -v"
assert 1993

CAT_ARGS="-e -E -b --number-nonblank -n -s -t -T -v"
assert 1994

CAT_ARGS="-e -E -b --number-nonblank -n --squeeze-blank -t -T -v"
assert 1995

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -t -T"
assert 1996

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -t -v"
assert 1997

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -T -v"
assert 1998

CAT_ARGS="-e -E -b --number-nonblank --number -s -t -T -v"
assert 1999

CAT_ARGS="-e -E -b --number-nonblank --number --squeeze-blank -t -T -v"
assert 2000

CAT_ARGS="-e -E -b --number-nonblank -s --squeeze-blank -t -T -v"
assert 2001

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -t -T"
assert 2002

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -t -v"
assert 2003

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -T -v"
assert 2004

CAT_ARGS="-e -E -b -n --number -s -t -T -v"
assert 2005

CAT_ARGS="-e -E -b -n --number --squeeze-blank -t -T -v"
assert 2006

CAT_ARGS="-e -E -b -n -s --squeeze-blank -t -T -v"
assert 2007

CAT_ARGS="-e -E -b --number -s --squeeze-blank -t -T -v"
assert 2008

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 2009

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 2010

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 2011

CAT_ARGS="-e -E --number-nonblank -n --number -s -t -T -v"
assert 2012

CAT_ARGS="-e -E --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 2013

CAT_ARGS="-e -E --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 2014

CAT_ARGS="-e -E --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 2015

CAT_ARGS="-e -E -n --number -s --squeeze-blank -t -T -v"
assert 2016

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 2017

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 2018

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 2019

CAT_ARGS="-e -b --number-nonblank -n --number -s -t -T -v"
assert 2020

CAT_ARGS="-e -b --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 2021

CAT_ARGS="-e -b --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 2022

CAT_ARGS="-e -b --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 2023

CAT_ARGS="-e -b -n --number -s --squeeze-blank -t -T -v"
assert 2024

CAT_ARGS="-e --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2025

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 2026

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 2027

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 2028

CAT_ARGS="-E -b --number-nonblank -n --number -s -t -T -v"
assert 2029

CAT_ARGS="-E -b --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 2030

CAT_ARGS="-E -b --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 2031

CAT_ARGS="-E -b --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 2032

CAT_ARGS="-E -b -n --number -s --squeeze-blank -t -T -v"
assert 2033

CAT_ARGS="-E --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2034

CAT_ARGS="-b --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2035

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -t -T"
assert 2036

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -t -v"
assert 2037

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -T -v"
assert 2038

CAT_ARGS="-e -E -b --number-nonblank -n --number -s -t -T -v"
assert 2039

CAT_ARGS="-e -E -b --number-nonblank -n --number --squeeze-blank -t -T -v"
assert 2040

CAT_ARGS="-e -E -b --number-nonblank -n -s --squeeze-blank -t -T -v"
assert 2041

CAT_ARGS="-e -E -b --number-nonblank --number -s --squeeze-blank -t -T -v"
assert 2042

CAT_ARGS="-e -E -b -n --number -s --squeeze-blank -t -T -v"
assert 2043

CAT_ARGS="-e -E --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2044

CAT_ARGS="-e -b --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2045

CAT_ARGS="-E -b --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2046

CAT_ARGS="-e -E -b --number-nonblank -n --number -s --squeeze-blank -t -T -v"
assert 2047
